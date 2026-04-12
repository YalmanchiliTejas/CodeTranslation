#include<iostream>
//#include<CastingInterop.h>
#include<string>
using namespace std;

int main()
{
    char arr[3];
    int arr1[3];
    string y;
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    string s[1000];
    for (int i = 0; i < 3; i++)
    {
        s[i] = arr[i];

    }
    for (int i = 0; i < 3; i++)
    {
        s[i] += s[i + 1] + s[i + 2];
    }

    //cout << s[0];
    string w;
    w = s[0];
    //cout << w;
    int num = stoi(w);
    if (num % 4 == 0)
        cout << "YES";
    else
        cout << "NO";
}