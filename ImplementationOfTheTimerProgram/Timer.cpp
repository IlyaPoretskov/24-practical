#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int main()
{
    while (true)
    {
        tm* gap;

        cout << "Input the time you want to mark (min:sec): ";
        time_t temp = time(nullptr);
        gap = localtime(&temp);
        cin >> get_time(gap, "%M:%S");
        temp = time(nullptr);
        int gapSeconds = (gap->tm_min * 60) + gap->tm_sec;
        time_t reqTime = time(nullptr) + gapSeconds;

        while(temp != reqTime)    temp = time(nullptr);

        cout << "DING! DING! DING!" << endl;
    }
}