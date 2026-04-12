#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long int min_value = 100000000000000;
    int max_C = max(X, Y);
    for(int i = 0; i <= max_C; i++) {
        long long int tmp = 2 * i * C + max(X-i, 0) * A + max(Y-i, 0) * B;
        min_value = min(min_value, tmp);
    } 
    cout << min_value << endl;
    return 0;
}