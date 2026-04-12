#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <complex>
using namespace std;

#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n) REP(i, 0, n)


int main()
{
        int n;
        while (cin >> n, n) {
                vector<int> vs = vector<int>(n);
                rep(i, n) cin >> vs[i];
                sort(vs.begin(), vs.end());
                int ans = 0;
                REP(i, 1, n-1)
                        ans += vs[i];
                ans /= n-2;
                cout << ans << endl;
        }
        return 0;
}