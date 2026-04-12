#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 100005
#define ll long long
#define slld(t) scanf("%I64d",&t)
#define sd(t) scanf("%d",&t)
#define ss(x) scanf("%s",x)
#define pd(t) printf("%d\n",t)
#define plld(t) printf("%I64d\n",t)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define FF first
#define SS second
#define pb(x) push_back(x)
#define ub upper_bound
#define lb lower_bound
#define vi vector<int>
#define vpii vector<pii >
#define vll vector<ll>
#define clr(x) memset(x,0,sizeof(x))
#define fil(x) memset(x,MAX,sizeof(x))
#define sws ios::sync_with_stdio(false); cin.tie(0)
#define pi acos(-1)
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I <= (B); ++I)
using namespace std;
const ll INF = 2147483647;
ll digitsum (ll num)
{
    ll sum = 0 ;
    while (num != 0)
    {
        sum+=(num%10);
        num/=10;
    }
    return sum;
}
bool isPrime[MAX+1];
void sieve(int n) 
{
    for(int i = 0; i <= n;++i) 
    {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= n; ++i) 
    {
         if(isPrime[i] == true) 
         {
             for(int j = i * i; j <= n ;j += i)
                 isPrime[j] = false;
        }
    }
}
#define matrix vector< vector<ll> >
matrix matmul(matrix &a, matrix &b){
    int i, j, k, n = a.size();
    matrix ans (n, vector<ll>(n));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            ll temp = 0;
            for(k=0;k<n;k++)    temp = (temp + a[i][k] * b[k][j]) % MOD;
            ans[i][j] = temp;
        }
    return ans;
}
matrix matpwr(matrix &a, ll p)
{
    int n = a.size();
    matrix ans(n, vector<ll> (n));
    for(int i=0;i<n;i++)    ans[i][i] = 1;
    while(p)
    {
        if(p&1) ans = matmul(ans, a);
        a = matmul(a, a);
        p >>= 1;
    }
    return ans;
}
ll pwr(ll base, ll p, ll mod = MOD)
{
   ll ans = 1;
    while(p)
    {
        if(p & 1)   ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        p /= 2;
    }
    return ans;
}
ll gcd(ll a, ll b){
    if(b == 0)  return a;
    return gcd(b, a%b);
}
ll lcm(ll a, ll b){
    return (a*b) / gcd(a, b);
}
const int N = 2e5+5 ;
int n ;
int dist[N];
set<int> s[N];
set<int> :: iterator it ;
int main()
{
    sws;
    //clock_t clk;
    //clk = clock();
    //freopen("a.in", "r", stdin); 
    //freopen("a.out", "w", stdout);

    int r, g, b ;
    cin >> r >> g >> b ;
    int num = 100*r+10*g+b ;
    if(num%4) cout<<"NO";
    else cout<<"YES" ;

    //clk = clock() - clk;
    //cout << fixed << setprecision(6) << "Time: " << ((double)clk)/CLOCKS_PER_SEC << "\n";
    return 0;
}