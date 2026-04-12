#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000001
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int main() {

    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];
    vector<int> minimum(N, INF);
    for (int i = N - 1; i >= 0; i--) {
        *upper_bound(minimum.begin(), minimum.end(), A[i]) = A[i];
    }
    int ans = 0;
    rep(i,N) if (minimum[i] < INF) ans = i;

    cout << ans + 1 << endl;
    
    return 0;
}