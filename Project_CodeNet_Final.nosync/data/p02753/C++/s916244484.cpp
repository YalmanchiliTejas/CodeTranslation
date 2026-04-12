#include <iostream>
#include <string>
using namespace std;
#define MAX_INPUT_NUM 3

int main()
{
    char inp[MAX_INPUT_NUM];
    for (int i = 0; i < MAX_INPUT_NUM; i++)
    {
        cin >> inp[i];
    }
    for (int i = 1; i < MAX_INPUT_NUM; i++)
    {
        if (inp[i] != inp[0])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
