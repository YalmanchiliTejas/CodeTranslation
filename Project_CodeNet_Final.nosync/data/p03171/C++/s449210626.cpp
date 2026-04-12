#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) {
os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
    return os << "(" << P.first << "," << P.second << ")";}

// #define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
typedef long long ll;
typedef double ld;
#define pll pair<ll,ll>
#define pii pair<int, int>
#define pb push_back
#define mp(x, y) make_pair((x), (y))
#define F first
#define S second
#define I insert
#define vi vector<int>
#define vll vector<ll>
#define vpll vector<pll>
#define all(x) (x).begin(), (x).end()
#define sz(x) (ll)(x).size()
   
const ll Mod = 1e9 + 7;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int n; cin >> n;
    ll Arr[n+1];
    for(int i = 1 ;i <= n; i++)
        cin >> Arr[i];
    
    if(n == 1){
        cout << Arr[1] << endl;
        return 0;
    }

    ll dp[n+1][n+1];
    memset(dp , 0 , sizeof(dp));

    for(int i = 1 ;i <= n; i++)
        dp[i][i] = Arr[i];

    for(int l = 2 ;l <= n ;  l++){
        for(int i = 1; i<= n-l+1 ; i++){
            int j = i+l-1;
            ll a = Arr[i] + min( dp[i+1][j-1] , dp[i+2][j] );
            ll b = Arr[j] + min( dp[i+1][j-1] , dp[i][j-2] );
            dp[i][j] = max(a , b);
            
        }
    }
    cout << dp[1][n] - min( dp[2][n] , dp[1][n-1] ) << endl;

    return 0;
} 