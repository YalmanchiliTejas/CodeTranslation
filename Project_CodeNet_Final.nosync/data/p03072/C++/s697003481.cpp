#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int main(int argc, char **argv)
{
    int N;
    cin >> N;
    int H[N];
    REP(i, N) cin >> H[i];

    int c = 1;
    int m = H[0];
    FOR(i, 1, N) {
        if (H[i] >= m) {
            c++;
            m = H[i];
        }
    }
    cout << c << endl;
    return 0;
}
