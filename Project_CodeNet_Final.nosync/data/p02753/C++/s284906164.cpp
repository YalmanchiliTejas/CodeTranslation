#include <bits/stdc++.h>

using namespace std;

int main()
{
    string S;
    cin >> S;
    bool exist = false;
    char x = S[0];
    for (int i = 1; i < S.size(); ++i)
    {
        if (x != S[i])
        {
            cout << "Yes" << endl;
            exist = true;
            break;
        }
    }
    if (!exist)
    {
        cout << "No" << endl;
    }
}