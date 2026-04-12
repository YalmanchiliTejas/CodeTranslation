#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define rep3(i, k, n) for (int i = k; i < n; i++)
#define sz(s) (int)s.size()
#define F first
#define S second

int main() {
    int s, t; cin >> s >> t;
    int p, q, M; cin >> p >> q >> M;
    int y; cin >> y;
    cout << (y ^ s ^ t) << endl;
    return 0;
}
