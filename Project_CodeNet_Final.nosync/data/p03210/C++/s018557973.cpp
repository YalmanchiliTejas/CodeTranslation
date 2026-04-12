#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using vint = vector<int>;

#define FOR(i, a, b) for(int64 i=(a); i<(b); i++)
#define ROF(i, a, b) for (int64 i=(a)-1; i>=(b); --i)
#define REP(i, n) FOR(i, 0, n)
#define PRE(i, n) ROF(i, n, 0)

#define ALL(x) (x).begin(),(x).end()
#define OUT(x) cout << (x) << endl;
#define DUMP(x) cerr << (x) << endl;

#define INF INFINITY
#define eps 1e-14

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int i;
    cin >> i;

    if (i == 3 or i == 5 or i == 7) {
        OUT("YES")
    }else{
        OUT("NO")
    }

    return 0;
}