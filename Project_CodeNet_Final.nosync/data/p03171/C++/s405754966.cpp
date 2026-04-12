#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,s,n) for(int i=(s); i<(n); i++)
#define all(v) v.begin(),v.end()
#define outve(v) for(auto i : v) cout << i << " ";cout << endl
#define outmat(v) for(auto i : v){for(auto j : i) cout << j << " ";cout << endl;}
#define in(n,v) for(int i=0; i<(n); i++){cin >> v[i];}
#define out(n) cout << (n) << endl
#define fi first
#define se second
#define pb push_back
#define mod 1000000007
#define infi 1900000000
#define infl 1100000000000000000
#define cyes cout << "Yes" << endl
#define cno cout << "No" << endl
#define csp << " " <<
#define outset(n) cout << fixed << setprecision(n);
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vs = vector<string>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vvp = vector<vector<pair<int,int>>>;
template<typename T> using ve = vector<T>;
template<typename T> using pq2 = priority_queue<T>;
template<typename T> using pq1 = priority_queue<T,vector<T>,greater<T>>;
template<typename T> bool chmax(T &a, T b) {if(a < b) {a = b;return 1;}return 0;}
template<typename T> bool chmin(T &a, T b) {if(a > b) {a = b;return 1;}return 0;}




int main(){

    int N;
    cin >> N;
    vl a(N);
    in(N,a);
    
    vvl dp(7100,vl(7100,0));
    
    reps(aa,1,N+1){
        rep(i,N+1){
            int j = aa+i;
            if((N-(j-i)) % 2 == 0){
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            }else{
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }
    
 
    //outmat(dp);
    cout << dp[0][N] << endl;
    
    

    return 0;
}
