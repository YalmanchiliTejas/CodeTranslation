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
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
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
ll p=1e9+7;
const int N=2e5+5;
ll add(ll a,ll b){
    ll t=(a+b);
    if(t>=p)t-=p;
        return t;
}
ll sub(ll a,ll b){
    ll t=a-b+p;
    t=t%p;
    return t;
}
ll power(ll a,ll x){
    ll r=1;
    while(x!=0){
        if(x%2==1){
            r=r*a;r%=p;
        }
        a=a*a;a%=p;
        x=x/2;
    }
    return r;
}
ll mul(ll a,ll b){
    ll t=(a*b);
    if(t>=p)t%=p;
    return t;
}
int main() {
  
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int T=1;
    // cin>>T;
    while(T--){
        ll n ;cin>>n;
        ll a[n];
        rep(i,n)cin>>a[i];
        ll dp[n][3];
        ll inf=-(1e16);
        rep(i,n)rep(j,3)dp[i][j]=inf;
        dp[0][0]=0;dp[0][1]=0;dp[0][2]=0;
        dp[1][0]=a[1];
        dp[1][1]=a[0];
        repA(i,2,n-1){
            
            dp[i][0]=a[i]+max({dp[i-2][0],dp[i-2][1],dp[i-2][2]});
            
            dp[i][1]=a[i-1]+max(dp[i-2][1],dp[i-2][2]);

            if(i%2==0){
                dp[i][2]=a[i-2];
                if(i!=2){
                    dp[i][2]+=dp[i-3][1];
                }
            }
               
        }
        repA(i,0,n-1){
            // cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
        }
        ll ans;
        ans=max(dp[n-1][0],dp[n-1][1]);
        if(n%2)ans=max(ans,dp[n-1][2]);
        cout<<ans;
    }   
    timecalculater();
    return 0;   
} 
