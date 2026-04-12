#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;

typedef long long LL;
typedef long double ldouble;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int graph[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0; i < 10; ++i) {
        graph[i][i] = 1;

    }

    int n, m;
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;

    }

    vector<int> v;
    for(int i = 1; i <= n; ++i) {
        v.pb(i);

    }

    int c = 0;
    do {
        if(v[0] != 1) continue;
        bool f = true;
        for(int i = 1; i < v.size(); ++i) {
            if(graph[v[i]][v[i - 1]] == 0) f = false;

        }
        if(f) ++c;

    } while(next_permutation(all(v)));
    cout << c << endl;
    return 0;
}

