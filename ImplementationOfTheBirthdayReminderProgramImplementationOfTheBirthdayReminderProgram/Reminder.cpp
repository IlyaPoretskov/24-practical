#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;


int translate_the_month_number(int n)
{
    switch (n)
    {
    case 1:
        return 31;
        break;
    case 2:
        return 59;
        break;
    case 3:
        return 90;
        break;
    case 4:
        return 120;
        break;
    case 5:
        return 151;
        break;
    case 6:
        return 181;
        break;
    case 7:
        return 212;
        break;
    case 8:
        return 243;
        break;
    case 9:
        return 273;
        break;
    case 10:
        return 304;
        break;
    case 11:
        return 334;
        break;
    case 12:
        return 365;
        break;
    default:
        return 0;
        break;
    }
}

int calculate_gap(tm a, tm b)
{
    int a_days = translate_the_month_number(a.tm_mon) + a.tm_mday;
    int b_days = translate_the_month_number(b.tm_mon) + b.tm_mday;

    return (360 + (b_days - a_days)) % 360;
}

struct person
{
    string name = "";
    tm birth;
    int gap;
};

int main()
{
    vector<person> people;
    
    while (true)
    {
        person current_person;

        cout << "Input person's name: ";
        cin >> current_person.name;

        if (current_person.name == "end")
        {
            break;
        }
        cout << "Input birthday year/month/day: ";
        time_t t = time(nullptr);
        current_person.birth = *localtime(&t);
        cin >> get_time(&current_person.birth, "%Y/%m/%d");
        people.push_back(current_person);
    }

    time_t temp = time(nullptr);
    tm current_time = *localtime(&temp);


    for (int i = 0; i < people.size(); i++)
    {
        if (people[i].birth.tm_mday == current_time.tm_mday && people[i].birth.tm_mon == current_time.tm_mon)
        {
            temp = time(nullptr);
            current_time = *localtime(&temp);
            cout << put_time(&current_time, "%d/%m") << "  Today is " << people[i].name << "'s birthday!" << endl;
        }
    }

    temp = time(nullptr);
    current_time = *localtime(&temp);

    for (int i = 0; i < people.size(); i++)
        people[i].gap = calculate_gap(current_time, people[i].birth);
    
    int minGapIndex = 0;

    for (int i = 0; i < people.size(); i++)
        if (people[i].gap <= people[minGapIndex].gap)
            minGapIndex = i;
    
    cout << people[minGapIndex].name << "'s birthday is the nearest!" << endl;
    system("pause");  

}