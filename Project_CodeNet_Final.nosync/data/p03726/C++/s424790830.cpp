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
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#include <functional>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<ll, ll, ll, ll> tlglglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
typedef unsigned int uint;
typedef unsigned long long ull;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;
void yesno(bool ok, string yes = "Yes", string no = "No") {
    if (ok) {
        cout << yes << endl;
    } else {
        cout << no << endl;
    }
}

struct edge {
    ll to, cost;
};

int N;
// vector<edge> G[1000000];
VV<edge> G(1000000);
V<ll> d(1000000);

void addedge(VV<edge>& G, int st, int ed, ll co) {
    edge e;
    e.to = ed;
    e.cost = co;
    G[st].push_back(e);
}

//根付き木を作る。parentVectorに親nodeの番号が入る。
//parentVector[root] = -1
//treeRankVectorにはnodeのrankが入る。rootのrankは0
//subTreeSizeVectorには、そのnodeを根とする部分木のサイズが入る。
vector<ll> par;
vector<ll> treeRank;
vector<ll> subTreeSize;
void makeRootedTree(vector<ll>& parentVector, vector<ll>& treeRankVector, vector<ll>& subTreeSizeVector, ll vecSize, ll root) {
    parentVector = vector<ll>(vecSize);
    treeRankVector = vector<ll>(vecSize);
    assert(root < (ll)parentVector.size());
    parentVector[root] = -1;
    treeRankVector[root] = 0;
    queue<ll> que;
    que.push(root);
    while (!que.empty()) {
        ll node = que.front();
        que.pop();
        REP (i, 0, G[node].size()) {
            edge e = G[node][i];
            if (e.to != parentVector[node]) {
                parentVector[e.to] = node;
                treeRankVector[e.to] = treeRankVector[node] + 1;
                que.push(e.to);
            }
        }
    }

    //ここからはsubTreeSizeVectorの計算
    vector<ll> used(parentVector.size());
    subTreeSizeVector = vector<ll>(vecSize, 0);
    fill(used.begin(), used.end(), 0);
    REP(i, 0, parentVector.size()) {
        if (parentVector[i] != -1 && G[i].size() == 1) {
            que.push(i);
            used[i] = 1;
        }
    }
    while (!que.empty()) {
        ll node = que.front();
        que.pop();
        //rootも含めて子だけのときに何かやりたいときはここに書く
        subTreeSizeVector[node]++;
        if (parentVector[node] == -1) {
            continue;
        }
        ll parent = parentVector[node];
        used[parent]++;
        subTreeSizeVector[parent] += subTreeSizeVector[node];
        //ここに書く
        if ((parentVector[parent] == -1 && used[parent] == (ll)G[parent].size()) ||
            (parentVector[parent] != -1 && used[parent] == (ll)G[parent].size() - 1)) {
            que.push(parent);
        }
    }
}

bool ok = false;
vll num;
//根付き木の葉から根に向かって何か処理をする
//根付き森でもOK。根のparentは-1にしておく
void leafToRoot(vector<ll> &parentVector) {
    queue<ll> que;
    vector<ll> used(parentVector.size());
    num = vll(parentVector.size(), 0);
    fill(used.begin(), used.end(), 0);
    REP(i, 0, parentVector.size()) {
        if (parentVector[i] != -1 && G[i].size() == 1) {
            que.push(i);
            used[i] = 1;
        }
    }
    while (!que.empty()) {
        ll node = que.front();
        que.pop();

        //rootも含めて子だけのときに何かやりたいときはここに書く
        if (parentVector[node] != -1 && (parentVector.size() - subTreeSize[node]) % 2 == 1) {
            num[node]++;
        }
        if (num[node] >= 2) {
            ok = true;
        }

        if (parentVector[node] == -1) {
            continue;
        }
        ll parent = parentVector[node];
        used[parent]++;

        //ここに書く
        if (subTreeSize[node] % 2 == 1) {
            num[parent]++;
        }

        if ((parentVector[parent] == -1 && used[parent] == (ll)G[parent].size()) ||
            (parentVector[parent] != -1 && used[parent] == (ll)G[parent].size() - 1)) {
            que.push(parent);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    REP(i, 0, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        addedge(G, a, b, 1);
        addedge(G, b, a, 1);
    }
    makeRootedTree(par, treeRank, subTreeSize, N, 0);
    leafToRoot(par);
    yesno(ok, "First", "Second");
}
