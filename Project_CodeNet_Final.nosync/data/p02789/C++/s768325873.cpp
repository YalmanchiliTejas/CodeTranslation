#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define int long long
#define REP(i,N) for(i=0; i<n; i++)
using namespace std;
signed main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    if (n == m) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
    return 0;
}