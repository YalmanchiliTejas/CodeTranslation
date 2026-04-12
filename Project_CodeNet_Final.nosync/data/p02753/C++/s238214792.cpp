#include <iostream>
using namespace std;

int main()
{
    char arr[3];
    int i = 0;

    for (i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    if(arr[0] == arr[1] && arr[1] == arr[2])
        cout << "No";
    else
        cout << "Yes";

    return 0;
}