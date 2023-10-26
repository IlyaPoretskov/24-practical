#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

struct task_info
{
    string name;
    time_t start_time;
    time_t end_time;
};

template < typename T >

void add_to_array(T array[], T elem)
{
    int length = begin(array);

    T newArray[length + 1];

    for (int i = 0; i < length; i++)
        newArray[i] = array[i];

    newArray[length] = elem;
    array = newArray;
}

int main()
{
    string command = "";
    task_info tasks[1];
    task_info current_task;

    while (true)
    {
        cout << "Input command: ";
        cin >> command;
        if (command == "exit")
        {
            break;
        }
        else if (command == "begin")
        {

            if (current_task.name != "")
            {
                current_task.end_time = time(nullptr);
                add_to_array(tasks, current_task);
                current_task.name = "";
            }

            cout << "Input new task name: ";
            cin >> current_task.name;

            while (current_task.name == "")
            {
                cout << "Incorrect input, try again!\n";
                cout << "Input new task name: ";
                cin >> current_task.name;
            }

            current_task.start_time = time(nullptr);
        }
        else if (command == "end")
        {
            if (current_task.name != "")
            {
                current_task.end_time = time(nullptr);
                add_to_array(tasks, current_task);
                current_task.name = "";
            }
        }
        else if (command == "status")
        {
            for (int i = 0; i < sizeof(tasks); i++)
            {
                cout << current_task.name << ": ";
                double d = difftime(current_task.start_time, current_task.end_time);
                time_t temporaily = (time_t)d;
                tm* gap = localtime(&temporaily);
                cout << put_time(gap, "%H:%M:%S") << endl;
            }
            cout << current_task.name << endl;
            
        }
        else
        {
            cout << "Incorrect input, try again!\n";
        }
    }
    system("pause");
}