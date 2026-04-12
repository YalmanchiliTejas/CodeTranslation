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
const ll INF = 1e18+3;
const ll mod = 1e9 + 7; //998244353;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define print(x) cerr << #x << " is " << x << endl;

ll A[100001], sum[100001];

int main(void){
    ll N, X, M;
    cin >> N >> X >> M;
    vector<ll> PREV(M + 1, -1);
    
    A[0] = X;
    sum[0] = X;
    if (N == 1){
        cout << sum[0];
        return 0;
    }
    PREV[X] = 0;
    ll ans = 0;
    
    rep(i, N){
        A[i + 1] = A[i] * A[i] % M;
        sum[i + 1] = sum[i] + A[i + 1];
        //fprintf(stderr, "%d, %d, %d\n", i + 1, A[i + 1], sum[i + 1]);
        if (i + 1 == N - 1){
            cout << sum[i + 1];
            return 0;
        }
        
        if (PREV[A[i + 1]] == -1){
            PREV[A[i + 1]] = i + 1;
        } else {
            int p = PREV[A[i + 1]];
            int q = i + 1;
            ll ans = sum[p - 1];
            ans += (sum[q] - sum[p]) * (ll)((N - 1 - p)/(q - p));
            ll val = A[i + 1];
            reps(j, p, q){
                ans += val;
                if ((N - 1) % (q - p) == j % (q - p)){
                    cout << ans;
                    return 0;
                }
                val = val * val % M;
            }
        }
    }
    return 0;
}
   