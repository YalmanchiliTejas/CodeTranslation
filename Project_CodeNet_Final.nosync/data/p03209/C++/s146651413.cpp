#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define lcm(a, b) (a)/__gcd((a),(b))*(b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define endl '\n'

using namespace std;

typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1000000007;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<int> Div(int n) {
    vector<int> ret;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);

            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}


LL rec(int n, LL x) {
    if(n == 0) {
        return 1;

    }
    LL l, num;
    l = (1ll << (n + 1)) - 3;
    num = (1ll << n) - 1;

    if(x == 1) return 0;
    if(x <= l + 1) return rec(n - 1, x - 1);
    if(x == l + 2) return num + 1;
    if(x <= (l + 1) * 2) return num + 1 + rec(n - 1, x - l - 2);
    return num * 2 + 1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    LL x;
    cin >> n >> x;

    cout << rec(n, x) << endl;
    return 0;
}

