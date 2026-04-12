#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> isPair;
using vvll = vector< vector<ll> >;
using vll = vector<ll> ;
#define Pll pair<ll,ll>
#define vpll vector<pll>
#define sll set<ll>
#define mll map<ll,ll>

const ll inf=(ll)1e18;
const ll maxs = (ll)100+5;
const ll mod = (ll)1e9+7;
const ll oo = (ll) 1e18;

#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define LB lower_bound
#define UB upper_bound
#define line cout<<endl;
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define all(n) n.begin(),n.end()
#define present(s,x) (s.find(x) != s.end()) 
#define cpresent(s,x) (find(all(s),x) != s.end()) 
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++) 
#define fastio(); ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define mst(x,a) memset(x,a,sizeof(x))

const ll MAX=1e4+4;
const ll M = 1e2+5;
string s;
ll d,n;
ll dp[MAX][M][2];

ll go(ll pos,ll sum,ll isFree)
{
    if(pos==n)
        return sum==0;
    if(dp[pos][sum][isFree]!=-1)
        return dp[pos][sum][isFree];
    ll ans=0;
    for(ll i=0;i<10;i++)
    {
        if(isFree)
        {
            ans = ( ans + go(pos+1,(sum+i)%d,1) )%mod ;
        }
        else
        {
            if(i < s[pos]-'0')
                ans = ( ans + go(pos+1,(sum+i)%d,1) )%mod;
            if(i==s[pos]-'0')
                ans = ( ans + go(pos+1,(sum+i)%d,0) )%mod;
        }
    }
    return dp[pos][sum][isFree] = ans;
}

void solve()
{
    n=s.size();
    memset(dp,-1,sizeof dp);
    cout<<(go(0,0,0)-1+mod)%mod;
}

int main() {
    fastio();
	cin>>s>>d;
	solve();
	return 0;
}