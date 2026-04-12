#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    long double A,B;
    cin >> A >> B;
    A = 1.0/A;
    B = 1.0/B;
    cout << fixed << setprecision(50) << (1/(A+B)) << endl;
}
