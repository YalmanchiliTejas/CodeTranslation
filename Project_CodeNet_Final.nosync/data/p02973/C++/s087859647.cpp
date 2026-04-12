#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>
#include<iomanip> //cout << fixed << setprecision(15) << x << endl;

using namespace std;
typedef long long ll;
const int INF = 1e9 + 6;
const int MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()

int main() {
    int N; cin >> N;
    int A[N]; rep(i, N) cin >> A[i];
    deque<int> ans;
    ans.push_front(A[0]);
    rep(i, N - 1) {
        int key = (lower_bound(all(ans), A[i + 1]) - ans.begin()) - 1;
        if(key == -1) {
            ans.push_front(A[i + 1]);
        }else {
            ans[key] = A[i + 1];
        }
    }
    cout << ans.size() << endl;
}
