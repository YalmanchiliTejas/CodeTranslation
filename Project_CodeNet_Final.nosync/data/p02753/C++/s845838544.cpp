#include<bits/stdc++.h>
#define ll long long
#define db double
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define inf LONG_LONG_MAX
#define inf1 INT_MAX
using namespace std;
/*
ll mpow(ll a, ll b){
    if(!b)
        return 1;
    ll temp=mpow(a,b/2);
    temp=(temp*temp)%mod;
    if(b%2)
        return (a*temp)%mod;
    return temp;
}

ll _pow(ll a, ll b){
    if(!b)
        return 1;
    ll temp=_pow(a,b/2);
    temp=(temp*temp);
    if(b%2)
        return (a*temp);
    return temp;
}

ll mod_in(ll n){
    return mpow(n,mod-2);
}
*/
int main()
{
    fastio
    string s;
    cin>>s;
    sort(s.begin(), s.end());
    if(s[0]==s[2])
    {
        cout<<"No";
    }
    else
    {
        cout<<"Yes";
    }
    return 0;
}