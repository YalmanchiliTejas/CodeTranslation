#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
#define fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
ll mem[3005][3005],a[3005];
bool vis[N],vis1[N];
vector<ll>v[N];
pair<ll,ll>p[N],p1[N];
set<int>s;
map<string,ll>mp;
queue<ll>q;
ll mod=1e9+7,n;
ll dp( int l ,int r)
{
    if(l==r)
        return a[l] ;
    ll &ret=mem[l][r];
    if(ret!=-1)
        return ret;

    return mem[l][r]=max(a[l]-dp(l+1,r),a[r]-dp(l,r-1));
}
main()
{
    fast_IO
    int n;
    cin>>n;
    memset(mem,-1,sizeof mem);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<dp(0,n-1);


}








