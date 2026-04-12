#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, a, b = 0, z = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (a >= b) z++;
        b = max(b, a);
    }
    cout << z;
}
