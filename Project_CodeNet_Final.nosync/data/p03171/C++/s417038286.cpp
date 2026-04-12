#include <bits/stdc++.h>

#define int long long
#define ld long double
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define vt vector
#define pb push_back
#define u_s unordered_set
#define u_m unordered_map
#define p_q priority_queue

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
// if using oset remove define int long long
//#define oset tree<int32_t, null_type, less<int32_t>, rb_tree_tag, tree_order_statistics_node_update>

using namespace std;

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
//void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#define deb(x...) cout << "[" << #x << "] = ["; _print(x)
int __pow(int x, int y) {int res = 1;while(y>0){if(y&1) res*=x; y>>=1; x*=x;}return res;}
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}

const int N = 3e3+2, inf = 1e18;

int t, n, m, dp[N][N];

void solve()
{
    cin>>n;
    vt<int> a(n);
    for(int &x:a)
        cin>>x;
    for(int i = n-1; i>=0; i--)
    {
        for(int j = 0; j<n; j++)
        {
            if(i==j)
                dp[i][j] = a[i];
            else
                dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}
int32_t main()
{
	//#ifndef ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    t = 1;
    //cin>>t;
    for(int i = 1; i<=t; i++)
    {
        //cout<<"Case #"<<i<<":"<<endl;
        solve();
    }
}
