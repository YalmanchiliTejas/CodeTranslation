#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    string s; cin >> s;
    ll d = 0, cnta=0;
    for(ll i = 0 ; i < s.size(); i++)
    {
        if(s[i] == 'A') cnta++;
        else d++;
    }
    if(d != 0 && cnta != 0)
    {
        cout << "Yes" << '\n';
    }
    if(d == 0 || cnta == 0)
    {
        cout << "No" << '\n';
    }
    
}