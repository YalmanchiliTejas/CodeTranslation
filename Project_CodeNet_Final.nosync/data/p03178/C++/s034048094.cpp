
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define inf 1013161010
#define ninf -1013161010
#define mod 1000000007
#define ll long long
#define lf long double
#define in(x) scanf("%d",&x);
#define sz(x) ((int)x.size())
#define lld l64d
#define rep(i,n) for(i=0;i<n;i++)
#define rrep(i,n) for(i=n-1;i>=0;i--)
#define rep1(i,a,b) for(i=a;i<=b;i++)
#define rrep1(i,a,b) for(i=a;i>=b;i--)
#define stlfor(i,t) for(auto i =t.begin();i!=t.end();i++)
#define fr freopen("x.txt","r",stdin)
#define frc freopen("y.txt","w",stdout)
#define all(x) x.begin(),x.end()
#define set0(x) memset(x,0,sizeof(x))
#define dbg cout<<"yo "<<endl;
#define pset(n) fixed<<showpoint<<setprecision(n)

#define pii pair<int,int>
#define pll pair<ll,ll>
#define min_pq priority_queue<pll, vector<pll>, greater<pll> >
#define vpii vector<pair<int,int> >
#define vll vector<ll>
#define vpll vector<pair<ll,ll> >
#define si set<int>
#define mii map<int,int>
#define umii unordered_map<int,int>
#define vi vector<int>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define modulo %
#define moduloe %=

typedef tree<pii,null_type,less<pii>,rb_tree_tag,tree_order_statistics_node_update> OST;

ll toint(const string &s) { stringstream ss; ss << s; ll x; ss >> x; return x; }
ll add(ll a, ll b) {a+=b; while(a >= mod) a-= mod; while(a<0) a+= mod;}
ll mul(ll a, ll b) {return (a * 1LL *b % mod);}
string tostring ( ll number ){  stringstream ss; ss<< number; return ss.str();}

const lf pi = 2*acos(0);
const int nn = 500006;
const lf EPS = 0.000000001;

ll gcd(ll a,ll b){return (b==0)? a:gcd(b,a%b); }
void nope(int num = 0){ if(num==0) cout<<"NO"; else cout<<"-1"; exit(0); }

ll dp[10002][2][102];
string k;
int d;
ll cnt = 0;

ll counter(int idx, int high, int rem)
{
    if(idx == 10000)
    {
        if(rem == 0)
            return 1LL;
        else
            return 0LL;
    }

    int i, j;
    if(dp[idx][high][rem] != -1)
        return dp[idx][high][rem];

    cnt++;
    if(high == 0)
    {
        // if exceeded
        for(j=0;j<d;j++)
        {
            dp[idx][high][j] = 0;
            for(i=0;i<10;i++)
            {
                dp[idx][high][j] += counter(idx+1, high, (j - i + 20*d) modulo d);
            }
            dp[idx][high][j] moduloe mod;
        }
    }
    else
    {
        for(j=0;j<d;j++)
        {
            dp[idx][high][j] = 0;
            for(i=0;i <= k[idx] - '0'; i++)
            {
                dp[idx][high][j] += counter(idx+1, ((i == (k[idx] - '0')) ? 1 : 0), (j - i + 20*d) modulo d);
            }
            dp[idx][high][j] moduloe mod;
        }
    }
    return dp[idx][high][rem];
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll i,j,n,tt;
    tt=1;
    //cin>>tt;
    while(tt--)
    {

        memset(dp, -1, sizeof(dp));

        cin>>k;
        cin>>d;

        n = sz(k);
        rep(i, 10000 - n)
            k = '0' + k;

        cout<<((counter(0, 1, 0) - 1 + mod) modulo mod)<<endl;
    }
    return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?)
