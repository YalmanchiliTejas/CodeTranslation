#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                push_back
#define mp              make_pair
#define sz(a)           a.size()
#define mods(a, m)          ((a % m + m) % m)
#define md(a)               mods(a, MOD)
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define f first
#define s second
#define fore(i, b, e)     for (ll i = b; i < e; i++)
#define forr(i, b, e)     for (ll  i = b; i < e; i++)
#define endl '\n'


using namespace std;
//using namespace __gnu_pbds;
typedef long double       ld;

typedef pair<ll, ll>  ii;
typedef pair<ll,ii> iii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = ll(1e9 + 7);
const ll MOD = 1e9+7;
const double EPS = 1e-9;
const double PI = acos(-1);
#define tam 1000003
ll dp[2][5][tam];
string t;
ll f(ll equal,ll k,ll pos)
{
    if (k<0)
        return 0;
    if (pos==t.size())
    {
        return (k==0);
    }
    if (dp[equal][k][pos]!=-1)
        return dp[equal][k][pos];
    ll res=0;
    if (!equal)
    {
        forr(i,0,10)
        res+=f(equal,k-(i!=0),pos+1);

    }
    else
    {
        forr(i,0,t[pos]-'0')
        {
            res+=f(0,k-(i!=0),pos+1);
        }
        ll chr=t[pos]-'0';
        res+=f(1,k-(chr!=0),pos+1);
    }
    return dp[equal][k][pos]=res;

}
int main()
{    
    std::ios::sync_with_stdio(false); cin.tie(0);
    memset(dp,-1,sizeof dp);
    cin>>t;
    ll k;
    cin>>k;
    cout<<f(1,k,0)<<endl;

}   
// PLUS ULTRA!
