#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;
#define REP(i,n) for(int i=0;i<(int)n;++i)
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
for(int i = 0; i < (int)v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
string num2bit(ll num, ll len){
    string bit = "";
    REP(i, len){
    bit += char('0'+(num>>i & 1));
    }
    return bit;
}

ll dp[3][202020];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];


    ll res = 0;
    if(N%2==0){
        const ll INF = (1ll<<60);
        REP(i, 2)REP(j, 202020) dp[i][j] = -INF;
        dp[0][0] = 0;

        REP(i, N){
            if(i<N) chmax(dp[0][i+2], dp[0][i] + A[i]);
            if(i+1<N) chmax(dp[1][i+3], dp[0][i] + A[i+1]);
            if(i<N) chmax(dp[1][i+2], dp[1][i] + A[i]);
        }
        
        res = max(dp[0][N], dp[1][N+1]);
    }else{
        const ll INF = (1ll<<60);
        REP(i, 3)REP(j, 202020) dp[i][j] = -INF;
        dp[0][0] = 0;

        REP(i, N){
            if(i<N) chmax(dp[0][i+2], dp[0][i] + A[i]);
            if(i+1<N) chmax(dp[1][i+3], dp[0][i] + A[i+1]);

            if(i<N) chmax(dp[1][i+2], dp[1][i] + A[i]);
            if(i+1<N) chmax(dp[2][i+3], dp[1][i] + A[i+1]);

            if(i<N) chmax(dp[2][i+2], dp[2][i] + A[i]);
        }

        /*
        REP(i, 3){
            REP(j, N+2){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        */
        
        
        res = max(max(dp[0][N-1], dp[1][N]), dp[2][N+1]);

        ll tmp = 0;
        ll mi = INF;
        REP(i, N){
            if(i%2==0){
                tmp += A[i];
                chmin(mi, A[i]);
            }
        }
        tmp -= mi;
        chmax(res, tmp);
    }
    cout << res << endl;

    return 0;
}