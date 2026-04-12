#include <bits/stdc++.h>
#define MEM 1000
#define sanic ios_base::sync_with_stdio(0)
using namespace std;
int t,n;
string s;
int main()
{
    sanic;
    cin >> s;
    for(int i=0; i<s.size(); i++)
        if(s[i]=='A') n++;
    if(!n || n==s.size()) cout << "No";
    else cout << "Yes";
}
