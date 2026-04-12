#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;

    for (size_t i = 0; i < 3 - 1; i++)
    {
        if (S[i] != S[i + 1])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}
