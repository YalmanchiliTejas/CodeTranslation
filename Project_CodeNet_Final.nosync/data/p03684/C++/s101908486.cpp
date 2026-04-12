#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef complex<double> xy_t;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
ll inf = llmax / 2;
double eps = 1e-11;

struct unionFind {
    vector<int> data;
    unionFind(int size) : data(size, -1) {}
    
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x != y) {
            if(data[y] < data[x]) {
                swap(x, y);
            }
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int root(int x) {
        return (data[x] < 0) ? x : data[x] = root(data[x]);
    }

    int rank(int x) {
        return -data[root(x)];
    }
};

//cost,from,toの順
vector<tiii> T;
vector<tiii> Krusans;

ll Kruskal(int n) {
    sort(T.begin(), T.end());
    ll ans = 0;
    ll num = 0;
    unionFind u(n);
    int size = T.size();
    for (int i = 0; i < size; i++) {
        int cost = get<0>(T[i]);
        int from = get<1>(T[i]);
        int to = get<2>(T[i]);
        if (u.root(from) != u.root(to)) {
            u.unite(from, to);
            ans += cost;
            num++;
            tiii t = make_tuple(cost, from, to);
            Krusans.push_back(t);
        }
        if (num == n - 1) {
            break;
        }
    }
    return ans;
}

pii x[200000], y[200000];

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int xx, yy;
        cin >> xx >> yy;
        x[i] = pii(xx, i);
        y[i] = pii(yy, i);
    }
    sort(x, x + N);
    sort(y, y + N);
    for(int i = 0; i < N - 1; i++) {
        tiii t1 = make_tuple(x[i + 1].first - x[i].first, x[i].second, x[i + 1].second);
        T.push_back(t1);
        tiii t2 = make_tuple(y[i + 1].first - y[i].first, y[i].second, y[i + 1].second);
        T.push_back(t2);
    }
    ll ans = Kruskal(2 * (N - 1));
    cout << ans << endl;
}
