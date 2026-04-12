#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;

    multiset<int> m;
    REP(i, 0, N) {
        int a; cin >> a;
        auto itr = m.lower_bound(a);
        if (itr != m.begin()) m.erase(--itr);
        m.insert(a);
    }
    cout << m.size() << endl;
    return 0;
}