#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<int, int> i_i;

#define reps(i,s,n) for(int i = s; i < n; i++)
#define rep(i,n) reps(i,0,n)
#define ALL(v) v.begin(), v.end()
#define SZ(x) ((ll)(x).size())

const double PI  = acos(-1.0);
const double EPS = 1e-9;
const ll INF = 1e9+10;
const ll MOD = 1e9+7;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define print(x) cerr << #x << " is " << x << endl;
//#define print(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl; 

ll N;
vector<ll> A(2e5+1), S(2e5+1);
map<i_i, ll> dp;
ll solve(int i, int k){
    
    
    if (N - i == k * 2 - 1){
        return S[i];
    } else if (i > N - 1 || N - i < k * 2 - 1){
        return -1e15;
    }
    if (dp[make_pair(i, k)] != 0)return dp[make_pair(i, k)];
    ll ans = A[i] + solve(i + 2, k - 1);
    chmax(ans, A[i] + solve(i + 3, k - 1));
    chmax(ans, A[i] + solve(i + 4, k - 1));
    if (i + 1 < N){
        chmax(ans, A[i + 1] + solve(i + 3, k - 1));
        chmax(ans, A[i + 1] + solve(i + 4, k - 1));
        if (i + 2 < N){
            chmax(ans, A[i + 2] + solve(i + 4, k - 1));
        }
    }
    return dp[make_pair(i, k)] = ans;
}
    
int main() {
    cin >> N;
    
    rep(i, N)cin >> A[i];
    
    S[N - 1] = A[N - 1];
    for (int i = N - 3; i >= 0; i-=2){
        S[i] = S[i + 2] + A[i];
    }
    
    ll ans = solve(0, N/2);
    cout << ans;
    return 0;
}

