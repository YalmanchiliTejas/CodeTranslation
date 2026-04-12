#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int i = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int i = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define MP make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1 << 30;
const ll LINF = 1LL << 61;
const int MOD = 1e9 + 7;

ll N, X;
vector<ll> nums(55, 1), paties(55, 1);

ll f(ll n, ll x) {
    if(n == 0) {
        return 1;
    }
    if(x <= 1)
        return 0;
    else if(x > 1 && x < nums[n] / 2 + 1)
        return f(n - 1, x - 1);
    else if(x == nums[n] / 2 + 1)
        return paties[n - 1] + 1;
    else if(x > nums[n] / 2 + 1 && x < nums[n])
        return paties[n - 1] + 1 + f(n - 1, x - (nums[n] / 2 + 1));
    else if(x >= nums[n])
        return paties[n];
}

int main() {
    cin >> N >> X;
    for(int i = 0; i < N; i++) {
        nums[i + 1] = 2 * nums[i] + 3;
        paties[i + 1] = 2 * paties[i] + 1;
    }
    cout << f(N, X) << endl;

    return 0;
}