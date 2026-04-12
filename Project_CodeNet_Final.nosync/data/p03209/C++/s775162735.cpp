#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

vector<int> size(51, 1);
vector<int> MAX(51, 1);

int f(int n, int x) {
    if (n == 0) return x;
    if (x == 0) return 0;
    if (x < size[n - 1] + 2) return f(n - 1, x - 1);
    if (x == size[n - 1] + 2) return MAX[n - 1] + 1;
    if (x == size[n]) return MAX[n];
    return MAX[n - 1] + 1 + f(n - 1, x - size[n - 1] - 2);
}

signed main() {
    int N, X;
    cin >> N >> X;
    
    REP(i, 51) size[i] = 2 * size[i - 1] + 3;
    REP(i, 51) MAX[i] = MAX[i - 1] * 2 + 1;
    cout << f(N, X) << endl;
    return 0;
}
