#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pi pair<ll,int> 
#define pii pair<int,ll>
 
ll mod = 1e9+7;
ll INF = 1e17;
/*ll gcd(ll a,ll b)
{
    if(a==0)
    return(b);
    return(gcd(b%a,a));
}*/
int main()
{
    IOS
    string s;
    cin>>s;
    ll flag=0,flag1=0;
    for(ll i=0;i<3;i++)
    {
        if(s[i]=='A')
        flag=1;
        if(s[i]=='B')
        flag1=1;
    }
    if(flag&&flag1)
    cout<<"Yes";
    else
    cout<<"No";
    return(0);
}
