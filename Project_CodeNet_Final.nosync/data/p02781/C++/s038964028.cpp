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

vi num;
int dp[105][5][2],k;

int calc(int pos,int cnt,int f)
{
    if(pos==sz(num))
        return cnt==k;
    if(dp[pos][cnt][f]!=-1)
        return dp[pos][cnt][f];
    int ans=0,mx;
    if(!f)
        mx=num[pos];
    else
        mx=9;
    for(int d=0;d<=mx;d++)
    {
        int nf=f,ncnt=cnt;
        if(!f && d<mx)
            nf=1;
        if(d)
            ncnt++;
        if(ncnt<=k)
            ans+=calc(pos+1,ncnt,nf);
    }
    return dp[pos][cnt][f]=ans;
}

int solve(string s)
{
    for(int i=0;i<sz(s);i++)
    {
        num.pb(s[i]-'0');
    }
    fill(dp,-1);
    int ans=calc(0,0,0);
    return ans;
}

void solve()
{
    string s;
    cin>>s>>k;
    int ans=solve(s);
    cout<<ans<<endl;
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