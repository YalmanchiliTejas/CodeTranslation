#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

#define INF 2e+9
#define MAX_N 100000

int dp[MAX_N];
int n;
vector<int> a;

void solve() {
    fill(dp, dp+n, INF);
    for (int i=0; i<n; ++i) {
        *upper_bound(dp, dp+n, a[i]) = a[i];
    }
    cout << lower_bound(dp, dp+n, INF) - dp << endl;
}

int main() {
    cin >> n;
    a.resize(n);
    for(int i=n-1; i>=0; --i) cin >> a[i];
    solve();
    system("pause");
    return 0;
}