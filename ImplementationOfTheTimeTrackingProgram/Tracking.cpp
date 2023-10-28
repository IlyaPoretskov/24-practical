#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

struct task_info
{
    string name;
    time_t start_time;
    time_t end_time;
};


int main()
{
    string command = "";
    vector<task_info> tasks;
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

            cout << "Input new task name: ";
            cin >> current_task.name;

            if (current_task.name != "")
            {
                current_task.end_time = time(nullptr);
                tasks.push_back(current_task);
                current_task.name = "";
            }

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
                tasks.push_back(current_task);
                current_task.name = "";
            }
        }
        else if (command == "status")
        {
            for (int i = 0; i < sizeof(tasks) / 48; i++)
            {
                cout << tasks[i].name << ": ";
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