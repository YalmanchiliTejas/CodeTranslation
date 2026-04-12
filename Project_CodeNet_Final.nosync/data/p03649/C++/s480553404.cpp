#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int N;
    cin >> N;

    vector<ll> A(N);
    for (auto &i : A) cin >> i;

    auto check = [&]() {
        bool res = false;
        for (auto &i : A) {
            if (N <= i) res = true;
        }
        return res;
    };

    ll ans = 0;
    vector<ll> count(N);
    while (check()) {
        rep(i, N) {
            count[i] = A[i] / N;
        }
        ll sum = accumulate(count.begin(), count.end(), 0L);
        rep(i, N) {
            A[i] = A[i] % N + (sum - count[i]);
        }
        ans += sum;
    }

    cout << ans <<endl;
}