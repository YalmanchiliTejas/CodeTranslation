#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    sort(str.begin(),str.end());
    if(str[0] != str[2])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
