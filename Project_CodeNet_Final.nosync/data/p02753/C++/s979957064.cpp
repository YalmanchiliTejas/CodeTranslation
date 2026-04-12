#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
#define l  long
#define ll  long long
int main()
{
    fast
    string s;cin>>s;
    if(s[0]==s[1] && s[1]==s[2] && s[2]==s[0])
       cout<<"No";
       else
        cout<<"Yes";
    return 0;
}
