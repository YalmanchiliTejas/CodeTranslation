#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin>>s;
    int flag=0;
    if(s[0]==s[1]&&s[1]==s[2])flag=1;
    if(flag)cout<<"No";
    else cout<<"Yes";
    
}