#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=1e9+7;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;cin>>s;
    if(s[0]==s[1]&&s[1]==s[2]) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}
