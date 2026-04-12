#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstring>
#include<utility>
#include<cmath>
#include<assert.h>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>

#define int long long
using namespace std;
#define rep(i, n) for(int i=0;i<(n);++i)
typedef pair<int, int> pii;
const int INF = 1l << 60;
#define u_b upper_bound
#define l_b lower_bound

int N;
int A[50];

signed main() {
    cin >> N;
    rep(i, N) {
        cin >> A[i];
    }
    sort(A, A + N, greater<>());
    bool flag = true;
    int ans = 0;
    while (flag) {
        flag = false;
        rep(i, N) {
            if (A[i] >= N) {
                flag = true;
                int cnt = A[i] / N;
                A[i] -= (N + 1) * cnt;
                rep(j, N) {
                    A[j] += cnt;
                }
                ans += cnt;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
