#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()
typedef long long ll;
#define lim 1000000000000000001


ll root(ll x,vector<ll>&v)
{
    while(v[x]!=x)
    {
        v[x]=v[v[x]];
        x=v[x];
    }
    return x;
}

int main()
{
     fast;
    string s;
    cin>>s;
    ll cn=0,c2=0;
    for(int i=0;i<3;i++)
    if(s[i]=='A')
    cn++;
    else
    {
        c2++;
    }
    
    if(cn&&c2)
    cout<<"Yes\n";
    else
    {
        cout<<"No";
    }
    
     

    return 0;
}