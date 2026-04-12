#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>

using namespace std;
using ll = long long;

int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

#define CIN(T, x) T x; cin >> x;
#define CINS(T, x, N) vector<T> x(N); for(int i = 0; i < (N); i++) { cin >> x[i]; }
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << " "; } cout << "\n";
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << "\n";


int main() {

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int sum = A * X + B * Y;
    for (int i = 0; i <= max(X, Y) + 1; i++) {
        int temp = 0;
        temp += C * 2 * i;
        temp += max(A * (X - i), 0);
        temp += max(B * (Y - i), 0);
        sum = min(sum, temp);
    }

    cout << sum << "\n";

    return 0;
}