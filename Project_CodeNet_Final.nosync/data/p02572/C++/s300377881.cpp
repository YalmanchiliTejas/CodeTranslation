#include <iostream>
#include <cmath>

#include <vector>
#include <algorithm>
#include <limits>
#include <unordered_set>
#include <array>
#include <queue>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> aj(n);
    long base = pow(10, 9) + 7;
    aj[n-1] = a[n-1] % base;
    for (int i = n-2; i >= 0; --i) {
        aj[i] = (aj[i+1] + (a[i] % base)) % base;
    }

    long answer = 0;
    for (int i = 0; i < n - 1; ++i) {
        answer = (answer + (((a[i] % base) * aj[i+1]) % base)) % base;
    }
    cout << answer << endl;
}
