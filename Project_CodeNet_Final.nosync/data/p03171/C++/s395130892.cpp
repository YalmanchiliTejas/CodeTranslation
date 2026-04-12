#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
    long long dp1[3001][3001] = {}, dp2[3001][3001] = {};;
    for (int w = 0; w < n; w++) {
        for (int i = 0; i + w < n; i++) {
            if (w == 0) { dp1[i][i] = a[i]; dp2[i][i] = -a[i]; }
            else {
                dp1[i][i+w] = max(a[i] + dp2[i+1][i+w], a[i+w] + dp2[i][i+w-1]);
                dp2[i][i+w] = min(- a[i] + dp1[i+1][i+w], - a[i+w] + dp1[i][i+w-1]);
            }
        }
    }
    cout << dp1[0][n-1] << endl;
}
