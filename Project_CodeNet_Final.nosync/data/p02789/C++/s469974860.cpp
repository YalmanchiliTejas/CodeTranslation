
#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

using namespace std;

typedef long long ll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 10e16;
int inf = 10e8;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    os << "[ ";
    REP(i, vec.size()) {
        os << vec[i] << " ";
    }
    os << "]";

    return os;
}

template<typename T>
void dump_2d_mat(T &m, int N, int M) {
    REP(i, N) {
        REP(j, M) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    
    cout << fixed << setprecision(20);
    if (N > M) cout << "No";
    else cout << "Yes";
    cout << endl;
}
