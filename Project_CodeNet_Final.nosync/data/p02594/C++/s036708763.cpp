// written by : soumya_27
#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ld long double
#define mod ((int)1e9+7)//998244353//((int)1e18+7)
#define M_PI 3.14159265358979323846
// #define maxx ((int)1e7+7)
#define pb push_back
#define ins insert
#define F first
#define S second
#define ins insert
#define pii pair <int , int>
#define lb lower_bound
#define ub upper_bound
#define usefile freopen("input.txt","r",stdin); freopen("ou(tp)ut.txt","w",stdout);
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define test int t; cin >> t; while(t--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
int exp(int x,int y,int p){ int res=1; while(y) {if(y%2) res=(res*x%p)%p; x=(x*x)%p; y/=2; } return res;}
int expo(int x,int y){ int res=1; while(y) {if(y%2) res=(res*x%mod)%mod; x=(x*x)%mod; y/=2; } return res;}
int add(int a, int b) {return (a%mod + b%mod + mod)%mod;}
int sub(int a, int b) {return (a%mod - b%mod + mod)%mod;}
int mul(int a, int b) {return ((a%mod)*(b%mod) + mod)%mod;}
int inv(int x) {return expo(x, mod-2);}
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)     
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
using namespace std;
int fact[1000006];
// void facto() {fact[0] = 1; for(i=1 ; i<1000006 ; i++) fact[i] = mul(fact[i-1], i);}
// int ncr(int n, int r) { int res = fact[n]; res = mul(res, inv(fact[r])); res = mul(res, inv(fact[n-r])); return res;}
void solve()
{
    fast
    // test
    {
        int n, i, j, k;
        cin >> n;
        if(n > 29)
        	cout << "Yes\n";
        else cout << "No\n";
        
    }
}

signed main()
{
    // time__("solve")
    {
        solve();
    }
    return 0;
}