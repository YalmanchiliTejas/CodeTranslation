#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
using vs = vector<string>;
using vll = vector<long long>;
using vpii = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvs = vector<vector<string>>;
using vvb = vector<vector<bool>>;
using vvll = vector<vector<long long>>;
using pii = pair<int, int>;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define reps(i,n) for(int i = 1; i <= (int)(n); i++)
#define rrep(i,n) for(int i = (int)(n) - 1; i >= 0; i--)
#define rreps(i,n) for(int i = (int)(n); i > 0; i--)
#define FOR(i,a,b) for(int i = (int)(a); i <= (int)(b); i++)
#define RFOR(i,a,b) for(int i = (int)(a); i >= (int)(b); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define call(x) (x).cbegin(), (x).cend()
#define MAX(x) *max_element(all(x))
#define MIN(x) *min_element(all(x))
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) {if (b<a) {a=b; return 1;} return 0;}
const int INF = INT_MAX;
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

vi a;
ll dp[3100][3100];

void solve(int N, vi &a){
    ll ans = 0;
    int turn = 0;
    memset(dp, 0, sizeof(dp));

    for (int len = 1; len <= N; len++){
        for (int i = 0; i+len <= N; i++){
            int j = i+len;
            if ((N-len)%2 == 0) {
                dp[i][j] = max(dp[i+1][j] + a[i], dp[i][j-1] + a[j-1]);
            }
            else {
                dp[i][j] = min(dp[i+1][j] - a[i], dp[i][j-1] - a[j-1]);
            }
        }
    }

    cout << dp[0][N] << endl;
}

int main(){
    int N;
    cin >> N;
    a.resize(N);
    for(int i = 0 ; i < N ; i++){
        cin >> a[i];
    }
    solve(N, a);
    return 0;
}