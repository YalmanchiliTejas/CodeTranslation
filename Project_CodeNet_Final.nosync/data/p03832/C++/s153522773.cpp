#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i, b, e)     for (ll i = b; i < e; i++)
#define forr(i, b, e)     for (ll i = b; i < e; i++)
ll faster_in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = ll(1e9 + 7);
const ll MOD=INF;
const double EPS = 1e-9;
const double PI = acos(-1);
const ll tam =2100;


typedef long long LL;
ll dp[tam][tam];
ll vC[tam][tam],fact[tam];
ll pot(ll b,ll e)
{
    b%=MOD;
    ll res=1;
    while(e)
    {
        if (e&1)
            res*=b,res%=MOD;
        b*=b,b%=MOD;
        e/=2;
    }
    return res;
}
int
 main()
{
    //cout<<pot(2,3)<<' '<<pot(3,4)<<endl;
    std::ios::sync_with_stdio(false); cin.tie(0);
    vC[0][0]=fact[0]=1;
    forr(i,1,tam)
    {
        fact[i]=fact[i-1]*i;fact[i]%=MOD;
        vC[i][0]=vC[i][i]=1;
        forr(j,1,i)
        {
            vC[i][j]=vC[i-1][j]+vC[i-1][j-1];vC[i][j]%=MOD;
        }
    }
    ll n,A,B,C,D;
    cin>>n>>A>>B>>C>>D;
    memset(dp,0,sizeof dp);
    dp[0][A-1]=1;
    forr(X,A,B+1)
    {
        //dp[0][X]=1;
        forr(i,0,n+1)
        {
            ll K=X*C;
            ll ways=0,auxways;
            while(i>=K && K<=X*D)
            {
                auxways=(dp[i-K][X-1]*vC[n-(i-K)][K])%MOD;
                auxways*=fact[K];auxways%=MOD;
                auxways*=pot(pot(fact[X],K/X),MOD-2);auxways%=MOD;
                auxways*=pot(fact[K/X],MOD-2);auxways%=MOD;
                ways+=auxways;ways%=MOD;
                K+=X;
            }
            dp[i][X]=(ways+dp[i][X-1])%MOD;
        }

        /*cout<<X<<": ";
        forr(i,0,n+1)
        cout<<dp[i][X]<<' '<<i<<endl;
        cout<<endl;*/
    }
    cout<<dp[n][B]<<endl;
}
// PLUS ULTRA!