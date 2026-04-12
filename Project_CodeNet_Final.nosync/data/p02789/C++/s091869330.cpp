#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

#define FOR(i, b, e) for(int i=(b);i<(e);i++)
#define REP(i, n) FOR(i,0,n)

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;

int M, N;

int main() {
    cin >> N >> M;
    if (N == M) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
