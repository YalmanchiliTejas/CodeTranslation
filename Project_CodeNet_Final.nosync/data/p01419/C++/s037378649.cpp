#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for (int i=0; i<(n); ++i)
#define RREP(i, n) for (int i=(int)(n)-1; i>=0; --i)
#define FOR(i, a, n) for (int i=(a); i<(n); ++i)
#define RFOR(i, a, n) for (int i=(int)(n)-1; i>=(a); --i)

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()

#define DUMP(x) cerr<<#x<<" = "<<(x)<<endl
#define DEBUG(x) cerr<<#x<<" = "<<(x)<<" (L"<<__LINE__<<")"<<endl;

template<class T>
ostream &operator<<(ostream &os, const vector <T> &v) {
    os << "[";
    REP(i, SZ(v)) {
        if (i) os << ", ";
        os << v[i];
    }
    return os << "]";
}

template<class T, class U>
ostream &operator<<(ostream &os, const pair <T, U> &p) {
    return os << "(" << p.first << " " << p.second << ")";
}

template<class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using P = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

const ll MOD = 1e9 + 7;
const int INF = INT_MAX / 2;
const ll LINF = LLONG_MAX / 2;
const ld eps = 1e-9;

template<typename T>
struct edge {
    int src, to;
    T cost;
};

template<typename T>
using Graph = vector<vector<edge<T>>>;

using State = string::const_iterator;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    // ifstream in("in.txt");
    // cin.rdbuf(in.rdbuf());

    int R, C, M; cin >> R >> C >> M;
    vector<string> S(R);
    REP(i, R) cin >> S[i];

    vvi cost(R, vi(C)), costOn(R, vi(C)), costOff(R, vi(C));
    REP(i, R) {
        REP(j, C) {
            cin >> cost[i][j];
        }
    }
    REP(i, R) {
        REP(j, C) {
            cin >> costOn[i][j];
        }
    }
    REP(i, R) {
        REP(j, C) {
            cin >> costOff[i][j];
        }
    }

    vi Y(M), X(M);
    REP(i, M) cin >> Y[i] >> X[i];

    const int dy[] = {0, 1, 0, -1};
    const int dx[] = {1, 0, -1, 0};
    vector<vvi> time(R, vvi(C));
    int currentTime = 0;

    REP(i, M-1) {
        vvi dist(R, vi(C, INF));
        vvi dir(R, vi(C, -1));
        queue<pair<int,int>> que;
        que.emplace(Y[i], X[i]);
        dist[Y[i]][X[i]] = 0;
        time[Y[i]][X[i]].push_back(currentTime);

        while (!que.empty()) {
            int y, x;
            tie(y, x) = que.front(); que.pop();
            if (y == Y[i+1] and x == X[i+1]) break;

            REP(k, 4) {
                int ny = y + dy[k];
                int nx = x + dx[k];
                if (ny < 0 or nx < 0 or R <= ny or C <= nx or S[ny][nx] == '#') continue;
                if (chmin(dist[ny][nx], dist[y][x] + 1)) {
                    dir[ny][nx] = k;
                    que.emplace(ny, nx);
                }
            }
        }

        int y = Y[i+1], x = X[i+1];
        while (y != Y[i] or x != X[i]) {
            time[y][x].push_back(currentTime + dist[y][x]);
            int k = dir[y][x];
            y -= dy[k], x -= dx[k];
        }

        currentTime += dist[Y[i+1]][X[i+1]];
    }

    int total = 0;
    REP(i, R) {
        REP(j, C) {
            if (time[i][j].empty()) continue;
            int sum = costOn[i][j] + costOff[i][j];
            REP(k, SZ(time[i][j])-1) {
                sum += min(costOff[i][j] + costOn[i][j], cost[i][j] * (time[i][j][k+1] - time[i][j][k]));
            }
            total += sum;
        }
    }

    cout << total << endl;

    return 0;
}


