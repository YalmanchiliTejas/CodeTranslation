#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds; 

#define int long long
#define pb push_back
#define pf push_front
#define eb emplace_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define f first
#define s second
#define sz(x) (int)x.size()
#define endl "\n"
#define forn(i,n) for(int i=0;i<n;++i)
#define fore(i,l,r) for(int i=int(l);i<=int(r);++i)
#define rep(i,begin,end) for(__typeof(end) i=(begin);i!=(end);i++)
#define fill(a,value) memset(a,value,sizeof(a));
#define gcd(a,b) __gcd((a),(b))
#define watch1(x) cout<<(x)<<endl
#define watch2(x,y) cout<<(x)<<" "<<(y)<<endl
#define watch3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define fastio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

typedef long long ll;
typedef long double ld; 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;

const int INF = 9e18;
const int mod = 1e9 + 7;
const int N = 1e4 + 5;

vi num;
int dp[N][105][2],d;

int calc(int pos,int sum,int f)
{
    if(pos==sz(num))
        return sum==0;
    if(dp[pos][sum][f]!=-1)
        return dp[pos][sum][f];
    int ans=0,mx;
    if(!f)
        mx=num[pos];
    else
        mx=9;
    for(int dig=0;dig<=mx;dig++)
    {
        int nf=f,nsum=sum;
        if(!f && dig<mx)
            nf=1;
        nsum=(sum+dig)%d;
        ans+=calc(pos+1,nsum,nf);
        ans%=mod;
    }
    return dp[pos][sum][f]=ans;
}

int solve(string k)
{
    for(int i=0;i<sz(k);i++)
    {
        num.pb(k[i]-'0');
    }
    fill(dp,-1);
    int ans=calc(0,0,0);
    return ans;
}

void solve()
{
    string k;
    cin>>k>>d;
    int ans=solve(k);
    cout<<(ans-1+mod)%mod;
}

signed main()
{
    fastio;
    int t;
    //cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}