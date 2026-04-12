#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string S;
    cin >> S;
    string A = "No";
    for (int i = 0; i < 2; i++)
    {
        if (S.at(i) != S.at(i + 1))
        {
            A = "Yes";
            break;
        }
    }
    cout << A << endl;
}