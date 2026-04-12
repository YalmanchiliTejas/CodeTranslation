#include <bits/stdc++.h>
#ifdef __LOCAL
    #define DBG(X) cout << #X << " = " << (X) << endl;
    #define SAY(X) cout << (X) << endl;
#else
    #define DBG(X)
    #define SAY(X)
#endif

#ifdef __LOCAL
    #include <filesystem>
    namespace fs = std::filesystem;
#endif

using namespace std;
using ll = long long int;
 
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S> p) { for (auto el : p) cout << "[" << el.first << ";" << el.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for (auto el : v) cout << el << " "; return os; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for (auto& elem : ret) cin >> elem; return ret; }

const ll mod = 998244353;

int N,S;
vector<int> A;

void input(){
    fast_io();
    #ifdef __LOCAL
        fs::path p = __FILE__;
        fs::path input,output;
        input = output = p.parent_path();
        input += string("/input/") + string(p.stem()) + string(".txt");
        output += string("/output/") + string(p.stem()) + string(".txt");
        freopen(input.c_str(), "r", stdin);
        freopen(output.c_str(), "w", stdout);
    #endif
    cin >> N >> S;
    A = fetch_vec<int>(N);
}

// 部分和問題の発展系
int solve(){
    vector<vector<ll>> dp(N+1,vector<ll>(3000,0));
    dp[0][0] = 1;
    for (int i = 0; i < N; i++)
    {
        dp[i+1][0] += 1; 
        for (int j = 0; j <= 3000; j++)
        {
            (dp[i+1][j] += dp[i][j])%=mod;
            if(j-A[i]>=0) (dp[i+1][j] += dp[i][j-A[i]])%=mod;
            
        }
        
    }
    ll ans=0;
    for (int i = 0; i <= N; i++)
    {
        ans += dp[i][S];
        ans %= mod;
    }    
    cout << ans << endl;
    return 0;
}   

int main()
{
    input();
    solve();
    return 0;
}
