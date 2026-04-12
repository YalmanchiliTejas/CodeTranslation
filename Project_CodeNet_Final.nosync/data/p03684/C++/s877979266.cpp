#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class UnionFind {
public:
    // parent node index if not root index
    // minus size of the tree if root index
    std::vector<int> data;

    UnionFind( int n ) {
        data.resize( n, -1 );
    }

    int find( int x ) {
        if ( data[x] < 0 ) {
            return x;
        } else {
            int r = find( data[x] );
            data[x] = r;
            return r;
        }
    }

    void unite( int x, int y ) {
        int r = find( x );
        int s = find( y );
        if ( r != s ) {
            data[r] += data[s];
            data[s] = r;
        }
    }
};

ll solve() {
    ll N;
    cin >> N;
    ll x, y;
    vector<pair<ll,int>> X, Y;
    for ( int i = 0; i < N; i++ ) {
        cin >> x >> y;
        X.emplace_back(x, i);
        Y.emplace_back(y, i);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    priority_queue<pair<ll, pair<int, int>>> qx, qy;
    for ( int i = 0; i < N-1; i++ ) {
        ll dx = X[i+1].first - X[i].first;
        qx.push(make_pair(-dx, make_pair(X[i].second, X[i+1].second)));
        ll dy = Y[i+1].first - Y[i].first;
        qy.push(make_pair(-dy, make_pair(Y[i].second, Y[i+1].second)));
    }

    ll ans = 0;
    UnionFind u(N);
    while ( !qx.empty() || !qy.empty() ) {
        pair<ll, pair<int, int>> v;
        if ( qy.empty() ) {
            v = qx.top();
            qx.pop();
        } else if ( qx.empty() ) {
            v = qy.top();
            qy.pop();
        } else if ( -qx.top().first <= -qy.top().first ) {
            v = qx.top();
            qx.pop();
        } else {
            v = qy.top();
            qy.pop();
        }
        int i = v.second.first, j = v.second.second;
        if ( u.find(i) != u.find(j) ) {
            u.unite(i,j);
            ans += -v.first;
        }
    }
    return ans;
}

int main() {
    auto ans = solve();
    cout << ans << "\n";
    return 0;
}