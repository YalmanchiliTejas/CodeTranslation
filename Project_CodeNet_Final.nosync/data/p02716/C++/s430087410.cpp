#include <bits/stdc++.h>
#ifdef __LOCAL
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
    #include <filesystem>
    namespace fs = std::filesystem;
#else
    #define DBG(X)
    #define SAY(X)
#endif

using namespace std;

using ll = long long int;

const ll  LL_INF = (ll)(2e18);
static mt19937 _g(time(nullptr));
 
inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) cout << "[" << el.first << ";" << el << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }

int N;
vector<ll> A;
void input(){
    fast_io();
    #ifdef __LOCAL
        fs::path __p = __FILE__;
        fs::path __input, __output;
        __input = __output = __p.parent_path();
        __input += string("/input/") + string(__p.stem()) + string(".txt");
        __output += string("/output/") + string(__p.stem()) + string(".txt");
        freopen(__input.c_str(), "r", stdin);
        freopen(__output.c_str(), "w", stdout);
    #endif
    cin >> N;
    A.push_back(0LL); // 1-indexed
    for (int i = 1; i <= N; i++)
    {
        ll a;
        cin >> a;
        A.push_back(a);
    }
}

// long long dp[maxn][2][2];
// void solve()
// {
// 	for (int i = 0; i < maxn; i++)
// 		for (int j = 0; j < 2; j++)
// 			for (int k = 0; k < 2; k++)
// 				dp[i][j][k] = -inf;
 
// 	dp[1][0][0] = a[1], dp[1][1][0] = a[2], dp[1][0][1] = 0; 
//     for (int i = 2; i <= n / 2; i++)
//     {
//     	dp[i][0][0] = dp[i-1][0][0] + a[i*2-1];
//     	dp[i][1][0] = max(dp[i-1][0][0], dp[i-1][1][0]) + a[i*2];
//     	dp[i][1][1] = max(dp[i-1][0][1], dp[i-1][1][1]) + a[i*2];
//     	dp[i][0][1] = max(dp[i-1][0][1] + a[i*2-1], max(dp[i-1][0][0], dp[i-1][1][0])); 
//     }
 
//     if (n % 2 == 0)
//     	cout << max(dp[n/2][0][0], dp[n/2][1][0]) << endl; 
 
//     else 
//     	cout << max(dp[n/2][0][0], max(dp[n/2][1][0], a[n] + dp[n/2][0][1])) << endl; 
// }

int solve(){
    ll dp[100010][2][2];
    for (int i = 0; i <= N/2; i++)
    {
        dp[i][0][0] = -LL_INF;
        dp[i][0][1] = -LL_INF;
        dp[i][1][0] = -LL_INF;
        dp[i][1][1] = -LL_INF;
    }
    
    dp[1][0][0] = A[1];
    dp[1][1][0] = A[2];
    dp[1][0][1] = 0;
    dp[1][1][1] = 0;
    for (int i = 2; i <= N/2; i++)
    {
        dp[i][0][0] = dp[i-1][0][0]+A[2*i-1];      
        dp[i][1][0] = max(dp[i-1][0][0],dp[i-1][1][0])+A[2*i];
        dp[i][0][1] = max({dp[i-1][0][1]+A[2*i-1],dp[i-1][0][0],dp[i-1][1][0]});
        DBG(dp[i][0][0])
        DBG(dp[i][1][0])
        DBG(dp[i][0][1])
    }
    ll ans=max(dp[N/2][0][0],dp[N/2][1][0]);
    if(N%2==0) ans = max(dp[N/2][0][0],dp[N/2][1][0]);
    else ans = max({dp[N/2][0][0],dp[N/2][1][0],dp[N/2][0][1]+A[N]});
    cout << ans << endl;
    return 0;
}   

int maketestcase(int n=200000){
    #ifdef __LOCAL
        fs::path __p = __FILE__;
        fs::path __input, __output;
        __input = __output = __p.parent_path();
        __input += string("/input/") + string(__p.stem()) + string(".txt");
        __output += string("/output/") + string(__p.stem()) + string(".txt");
        // freopen(__input.c_str(), "r", stdin);
        freopen(__input.c_str(), "w", stdout);
    #endif

    cout << n << endl;
    ll mod=1e9+7;
    for (ll i = 0; i < n; i++)
    {
        cout << 0 << " ";
    }
    cout << endl;    
    return 0;
}

int main()
{
    input();
    solve();
    // maketestcase(10000);
    return 0;
}
