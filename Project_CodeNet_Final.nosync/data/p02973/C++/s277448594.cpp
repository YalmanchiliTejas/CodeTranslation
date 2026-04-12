#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    multiset<int> s;
    int ans = 0;
    rep(i, N)
    {
        auto it = s.lower_bound(A[i]);
        if (it == s.begin()) {
            s.insert(A[i]);
            // cout << "i: " << i << endl;
            // cout << A[i] << endl;
            ans++;
        } else {
            auto p = prev(it);
            s.erase(p);
            s.insert(A[i]);
        }
    }
    cout << ans << endl;
}