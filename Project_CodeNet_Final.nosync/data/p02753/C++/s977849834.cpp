#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
int main() 
{
    string s;
    cin>>s;
    if((s[0]==s[1]&&s[1]!=s[2])||(s[0]==s[2]&&s[0]!=s[1])||(s[1]==s[2]&&s[1]!=s[0]))
    cout<<"Yes";
    else
    cout<<"No";
}
        