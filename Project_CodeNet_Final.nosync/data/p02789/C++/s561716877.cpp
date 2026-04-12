#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using mii = map<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
using vl = vector<ll>;
using vll = vector<vl>;
using tpi = tuple<int, int, int>;

using vqi = vector<queue<int>>;
using vpi = vector<pii>;
using bs = bitset<60>;
using vbi = vector<bs>;
constexpr ll MOD = 1e9 + 7;


int main() {
    int N, M;
    cin >> N >> M;

    string ans;
    if (N == M) {
        ans = "Yes";
    } else {
        ans = "No";
    }

    cout << ans << endl;
    return 0;
}
