#include <bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    cin >> S;
    bool a_exist = false, b_exist = false;
    for (int i = 0; i < 3; i++)
    {
        if (S[i] == 'A')
            a_exist = true;
        if (S[i] == 'B')
            b_exist = true;
    }
    if (a_exist && b_exist)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}