#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a;
    string s;
    cin>>s;
    if(s[0]!=s[1] || s[0]!=s[2])
        cout<<"Yes";
    else if(s[0]==s[1] && s[0]==s[2])
        cout<<"No";
}

