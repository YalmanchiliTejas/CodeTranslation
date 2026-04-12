#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;
int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    multiset<ll> s;
    rep(i, N) {
        auto iter = s.lower_bound(A[i]);
        if (iter != s.begin()) {
            iter--;
            s.erase(iter);
        }
        s.insert(A[i]);
    }
    cout << s.size() << endl;
}