#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef unsigned long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
ll ans[505][505];
ll S[505], T[505], U[505], V[505];
ll a[505][505];
ll s[505], t[505], u[505], v[505];

bool validate();

bool h(int w, int idx) {
    ll tmp = a[w][0];
    if(a[w][0] == -1) {
        tmp = a[w][1];
    }
    if(s[w] == 0) {
        for(int i = 0; i < N; i++) {
            if(a[w][i] == -1) continue;
            tmp &= a[w][i];
        }
        if(tmp == 1 and u[w] == 0) a[w][idx] = 0;
    } else {
        for(int i = 0; i < N; i++) {
            if(a[w][i] == -1) continue;
            tmp |= a[w][i];
        }
        if(tmp == 0 and u[w] == 1) a[w][idx] = 1;
    }
    return a[w][idx] != -1;
}

bool g(int w, int idx) {
    ll tmp = a[0][w];
    if(a[0][w] == -1) {
        tmp = a[1][w];
    }
    if(t[w] == 0) {
        for(int i = 0; i < N; i++) {
            if(a[i][w] == -1) continue;
            tmp &= a[i][w];
        }
        if(tmp == 1 and v[w] == 0) a[idx][w] = 0;
    } else {
        for(int i = 0; i < N; i++) {
            if(a[i][w] == -1) continue;
            tmp |= a[i][w];
        }
        if(tmp == 0 and v[w] == 1) a[idx][w] = 1;
    }
    return a[idx][w] != -1;
}

void f(int d) {
    for(int i = 0; i < N; i++) {
        s[i] = S[i];
        t[i] = T[i];
        u[i] = (U[i] >> d) & 1LL;
        v[i] = (V[i] >> d) & 1LL;
        for(int j = 0; j < N; j++) {
            a[i][j] = -1;
        }
    }
    vector<int> row, column;
    for(int i = 0; i < N; i++) {
        if(s[i] and u[i] == 0) {
            for(int j = 0; j < N; j++) {
                a[i][j] = 0;
            }
        } else if(s[i] == 0 and u[i] == 1) {
            for(int j = 0; j < N; j++) {
                a[i][j] = 1;
            }
        } else {
            row.push_back(i);
        }
    }
    for(int i = 0; i < N; i++) {
        if(t[i] and v[i] == 0) {
            for(int j = 0; j < N; j++) {
                if(a[j][i] == 1) {
                    cout << -1 << endl;
                    exit(0);
                } else {
                    a[j][i] = 0;
                }
            }
        } else if(t[i] == 0 and v[i] == 1) {
            for(int j = 0; j < N; j++) {
                if(a[j][i] == 0) {
                    cout << -1 << endl;
                    exit(0);
                } else {
                    a[j][i] = 1;
                }
            }
        } else {
            column.push_back(i);
        }
    }
    /*
    cerr << "---" << d << "---" << endl;
    for(auto a : row) {
        cerr << a << " ";
    }
    cerr << endl;
    for(auto a : column) {
        cerr << a << " ";
    }
    cerr << endl;
    */
    if(row.size() >= 2 and column.size() >= 2) {
        for(int i = 0; i < row.size(); i++) {
            for(int j = 0; j < column.size(); j++) {
                a[row[i]][column[j]] = (i ^ j) & 1;
            }
        }
    } else if(row.size() == 1 and column.size() >= 1) {
        vector<int> sub;
        for(auto tmp : column) {
            if(!g(tmp, row[0])) sub.push_back(tmp);
        }
        for(auto val : sub) {
            //cerr << val << " ";
        }
        //cerr << endl;
        if(sub.size() >= 2) {
            for(int i = 0; i < sub.size(); i++) {
                a[row[0]][sub[i]] = i & 1;
            }
        } else if(sub.size() == 1) {
            for(int val = 0; val <= 1; val++) {
                a[row[0]][sub[0]] = val;
                if(validate()) break;
            }
        }
    } else if(column.size() == 1 and row.size() >= 1) {
        vector<int> sub;
        for(auto tmp : row) {
            if(!h(tmp, column[0])) sub.push_back(tmp);
        }
        for(auto val : sub) {
            //cerr << val << " ";
        }
        //cerr << endl;
        if(sub.size() >= 2) {
            for(int i = 0; i < sub.size(); i++) {
                a[sub[i]][column[0]] = i & 1;
            }
        } else if(sub.size() == 1) {
            for(int val = 0; val <= 1; val++) {
                a[sub[0]][column[0]] = val;
                if(validate()) break;
            }
        }
    }
    if(!validate()) {
        cout << -1 << endl;
        exit(0);
    }
    //cerr << "output: " << d << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans[i][j] |= (1LL << d) * a[i][j];
            //cerr << a[i][j] << " ";
        }
        //cerr << endl;
    }
}

bool validate() {
    for(int i = 0; i < N; i++) {
        if(s[i] == 0) {
            ll now = a[i][0];
            for(int j = 0; j < N; j++) {
                now &= a[i][j];
            }
            if(now != u[i]) {
                return false;
            }
        }
        if(s[i] == 1) {
            ll now = a[i][0];
            for(int j = 0; j < N; j++) {
                now |= a[i][j];
            }
            if(now != u[i]) {
                return false;
            }
        }
        if(t[i] == 0) {
            ll now = a[0][i];
            for(int j = 0; j < N; j++) {
                now &= a[j][i];
            }
            if(now != v[i]) {
                return false;
            }
        }
        if(t[i] == 1) {
            ll now = a[0][i];
            for(int j = 0; j < N; j++) {
                now |= a[j][i];
            }
            if(now != v[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> S[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> T[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> U[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> V[i];
    }
    if(N == 1) {
        if(U[0] == V[0]) {
            cout << U[0] << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    for(int d = 0; d < 64; d++) f(d);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(j != 0) cout << " ";
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}
