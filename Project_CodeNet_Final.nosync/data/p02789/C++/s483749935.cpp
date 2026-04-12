/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")*/
#include"bits/stdc++.h"
#define int ll
using namespace std;
using ll = long long ;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cout.setf(ios::fixed); cout.precision(20)
//#define endl '\n'
///       Author
///        ::
///    (  NOBODY  )
///   No Copyright .....You can copy and paste it without my permission...................................
/// !!!!!!!!!!!!!!!
#define pb push_back
#define N 1000020
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
typedef pair<int,int> ii;
void scan(vector<int>&v,int siz)
{
    v.resize(siz);
    for(auto &c:v)
        cin>>c;
}
void print(vector<ll>v)
{
    for(auto c:v)
        cout<<c<<' ';
    cout<<endl;
}
void view(deque<int>v)
{
    for(auto c:v)
        cout<<c<<' ';
    cout<<endl;
}
int fenwik[N];
void update(int pos,int val)
{
    while(pos<N)
    {
        fenwik[pos]+=val;
        pos+=(pos&(-pos));
    }
}
int get(int pos)
{
    int ans=0;
    while(pos>0)
    {
        ans+=fenwik[pos];
        pos-=(pos&(-pos));
    }
    return ans;
}
int a[N],mod=1e9+7;
int goy(int base,int pow)
{
    base%=mod;
    if(pow==0)return 1;
    int x=goy(base,pow/2);
    x=(x*x)%mod;
    if(pow%2)x=(base*x)%mod;
    return x;
}
multimap<int,int>mp;
vector<pair<int,int>>Get_all(int key)
{
    vector<pair<int,int>>vv;
    typedef multimap<int, int>::iterator MMAPIterator;
    pair<MMAPIterator, MMAPIterator> result = mp.equal_range(1);
    for (MMAPIterator it = result.first; it != result.second; it++)vv.push_back({it->ff,it->ss});
    return vv;
}
int n,m;
int dp[21][1001];
int go(int pos,int bef)
{
    if(pos==m)return 1;
    if(dp[pos][bef]!=-1)return dp[pos][bef];
    int ans=0;
    for(int i=bef;i<=n;i++)
    {
        ans+=go(pos+1,i);
        ans%=mod;
    }
    return dp[pos][bef]=ans;
}
int32_t main()
{
    FAST_IO;
  int a,b;
  cin>>a>>b;
  if(a>b)cout<<"No"<<endl;
  else cout<<"Yes"<<endl;
    return 0;
}
