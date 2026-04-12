#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
using ll = long long;
int main()
{
    int n,k;
    string s;
    cin >> n >> s >> k;
    char ch = s[k - 1];
    for(int i = 0;i < n;i++)
    {
        if(s[i] != ch)
        {
            s[i] = '*';
        }
    }
    cout << s << "\n";
    
    return 0;
}