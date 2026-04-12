#include <bits/stdc++.h>
using namespace std;
const auto start_time = std::chrono::high_resolution_clock::now();
void timecalculater(){
    #ifndef ONLINE_JUDGE
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time-start_time;
    cerr<<"Time Taken : "<<diff.count()<<"\n";
    #endif
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
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
#ifndef ONLINE_JUDGE
#define dbg(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a,v) memset(a, v, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
ll p=998244353;
const int N=2e5+5;
int main() {
  
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int T=1;
    // cin>>T;
    while(T--){
        ll n,s;cin>>n>>s;
        ll a[n+1];rep(i,n)cin>>a[i+1];
        ll dp[n+1][s+1];
        fill(dp,0);
        ll ans=0;
        ll pre[s+1]={0};
        for(ll i=1;i<=n;i++){
            if(a[i]<=s)
            dp[i][a[i]]=i;
            for(ll j=1;j<=s;j++){
                if(j>a[i]){
                    // dbg(i,pre[j-a[i]],j);
                    dp[i][j]=(pre[j-a[i]]);
                    dp[i][j]%=p;
                }
            }
            for(ll j=1;j<=s;j++){
                // dbg(dp[i][j]);
                pre[j]+=dp[i][j];pre[j]%=p;
            }
            // dbg(dp[i][s],pre[2],dp[i][s]);
            ans=ans+((n-i+1)*(dp[i][s]))%p;ans%=p;
            // dbg(ans);
        }
        cout<<ans<<endl;
    }   
    timecalculater();
    return 0;   
} 