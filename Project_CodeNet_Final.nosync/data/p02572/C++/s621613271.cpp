/*
  AUTHOR:SOURABH
  CREATED:27:08:20
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<pll , null_type, less< pll >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define W while
#define fn(i,x) for(i=0;i<x;i++)
#define fs(i,s,x) for(i=s;i<x;i++)
#define fr(i,x) for(i=x;i>=0;i--)
#define fit(it,s) for(it=s.begin();it!=s.end();it++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define mod 1000000007
#define MAX 100005
#define M 32

using namespace std;
using namespace __gnu_pbds;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll t,n,i,ans=0;
    t=1;
    //cin>>t;
    W(t--)
    {
        cin>>n;
        vll a(n),post(n);
        fn(i,n)
        cin>>a[i];
        post[n-1]=a[n-1];
        fr(i,n-2)
        post[i]=(a[i]+post[i+1])%mod;
        fn(i,n-1)
        {
            ans=(ans+(a[i]*post[i+1])%mod)%mod;
        }
        cout<<ans;
    }
    return 0;
}



