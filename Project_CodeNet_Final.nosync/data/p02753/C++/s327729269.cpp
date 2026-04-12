#include <bits/stdc++.h>
using namespace std;



int main()
{
    string str;
    cin >> str;
    for(int i = 1; i < 3; i++)
        if(str[i] != str[i-1])
        {
            cout << "Yes";
            return 0;
        }
    cout << "No";
}
