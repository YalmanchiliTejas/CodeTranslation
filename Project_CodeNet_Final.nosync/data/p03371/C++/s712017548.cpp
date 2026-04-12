#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int sum = numeric_limits<int>::max();
    for (int c = 0; c <= max(X, Y); ++c) {
        int tmp = c*2*C + max(0, X-c)*A + max(0, Y-c)*B;
        sum = min(sum, tmp);
    }
    cout << sum << endl;
}