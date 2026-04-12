#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    string s;
    cin >> s;
    int count[2] = {};
    for(int i = 0;i < s.size();i++)
    {
        count[s[i] - 'A']++;
    }
    if(count[0] && count[1])
    {
        cout << "Yes\n";
    }
    else
    {
        cout << "No\n";
    }
    
    return 0;
}