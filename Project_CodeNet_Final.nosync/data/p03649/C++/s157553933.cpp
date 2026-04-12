#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define sll set<ll>
#define mll map<ll,ll>
#define MOD 1000000007
#define fo(i,n) for(i=0;i<n;i++)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    #ifdef UJJWAL_HOME
        freopen("000.txt","r",stdin);
    #endif // UJJWAL_HOME

    ll n,i,j,k,t,q,a[51]={0};
    multiset<ll> m;
    cin>>n;

    fo(i,n)
    {
        cin>>a[i];
    }

    ll ans=0;
    while(true)
    {
        ll ma=0,b;
        fo(i,n)
        {
            if(ma<a[i])
            {
                ma=a[i];
                j=i;
            }
        }
        if(ma<n)
            break;

        b=ma/n;
        ans+=b;
        fo(i,n)
        {
            if(i==j)
                a[i]-=b*n;
            else
                a[i]+=b;
        }
    }

    cout<<ans;
    return 0;
}
