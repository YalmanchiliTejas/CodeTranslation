
#include <bits/stdc++.h>

#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define dump(x)  cerr << #x << " = " << (x) << endl
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl

using namespace std;

typedef long long LL;

template<typename T>
ostream& operator << (ostream& os, const vector<T>& vec) {
    os << "[ ";
    REP(i, vec.size()) {
        os << vec[i] << " ";
    }
    os << "]";

    return os;
}

int recurse(const int N, int *E, vector<int> o, int nn) {
    if (o.size() == N) return 1;

    int ret = 0;
    REP(i, N) {
        if (E[nn * N + i] == 1) {
            if (find(o.begin(), o.end(), i) != o.end()) continue;
            auto no = o; no.push_back(i);
            ret += recurse(N, E, no, i);
        }
    }

    return ret;


}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    int E[N * N];
    REP(i, N * N) E[i] = 0;

    int a, b;
    REP(i, M) {
        cin >> a >> b;
        --a; --b;
        E[a * N + b] = 1;
        E[b * N + a] = 1;
    }

    cout << recurse(N, E, {0}, 0) << endl;

}
