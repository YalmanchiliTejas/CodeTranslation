#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll

#define _GLIBCXX_DEBUG

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define ALL(vec) (vec).begin(), (vec).end()
#define REVALL(vec) (vec).rbegin(), (vec).rend()

#define fst first
#define pb push_back

const int MOD = (int)1e9 + 7;
const int INF = numeric_limits<int>::max();

signed main() {
    int N, M;

    cin >> N >> M;

    map<P, bool> mp;
    REP(i, M) {
        int A, B;
        cin >> A >> B;

        P p1 = make_pair(A, B);
        mp[p1] = true;

        P p2 = make_pair(B, A);
        mp[p2] = true;
    }

    int ans = 0;
    vector<int> vec;
    // 2~Nの(N-1)個 (インデックスは0~N-2)
    FORE(i, 2, N) {
        vec.pb(i);
    }

    do {
        // cerr << "perm" << endl;
        // for (auto node : vec) {
        //     cerr << node << " ";
        // }
        // cerr << endl;
        // hyphen();

        // その通り方が実行できたらOK
        // 1 → 1個目
        P p1 = make_pair(1, vec.at(0));
        if (!mp.count(p1)) {
            cerr << "not edge : " << 1 << " " << vec.at(0) << endl;
            continue;
        }

        // 1個目 → 2個目
        // ...
        // (N-2) → (N-1)
        bool ok = true;
        FORE(i, 1, N-2) {
            P p3 = make_pair(vec.at(i-1), vec.at(i));
            if (!mp.count(p3)) {
                ok = false;
                cerr << "not edge : " << vec.at(i-1) << " " <<  vec.at(i) << endl;
                break;
            }
        }
        if (!ok) {
            continue;
        }

        // カウントしたパスを出力
        cerr << "1 ";
        for (auto node : vec) {
            cerr << node << " ";
        }
        cerr << endl;

        ans += 1;
    } while (next_permutation(ALL(vec)));

    cout << ans << endl;
}
