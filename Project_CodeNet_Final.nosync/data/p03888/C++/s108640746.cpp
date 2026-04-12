#include <bits/stdc++.h>
using namespace std;

#define int long long
const double PI = 3.14159265358979323846;
typedef vector<int> vint;
typedef pair<int, int> pint;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int R1, R2;
signed main() {
    cin >> R1 >> R2;
    cout << setprecision(15) << (double)R1*R2 / (R1 + R2) << endl;
    return 0;
}