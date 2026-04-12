#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int INF = 1 << 30;
const ll LLINF = 1LL << 60;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    ll A[N]; rep(i, N) cin >> A[i];
    ll op[N] = {};
    ll ans = 0;
    while(true){
        bool ok = true;
        rep(i, N) if(A[i] >= N) ok = false;
        if(ok){
            cout << ans << endl;
            break;
        }

        rep(i, N) op[i] = 0;
        rep(i, N){
            if(A[i] >= N){
                //A[i]-kN <= N-1, kN >= A[i]-(N-1), k >= (A[i]-(N-1))/N
                op[i] = (A[i]-(N-1) + (N-1))/N;
            }
        }
        ll sum_op = 0; rep(i, N) sum_op += op[i];
        rep(i, N) A[i] += (sum_op - op[i]) - op[i]*N;
        ans += sum_op;
    }
    return 0;
}