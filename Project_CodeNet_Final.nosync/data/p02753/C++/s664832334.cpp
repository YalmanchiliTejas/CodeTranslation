#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s[0]==s[2])
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
