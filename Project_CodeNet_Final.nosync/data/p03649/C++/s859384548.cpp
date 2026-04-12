#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
using lint = long long;

int main() {
    lint N;
    cin >> N;
    vector<lint> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    lint ans = 0;
    while (true) {
        sort(a.begin(), a.end(), greater<lint>());

        lint num = a[0]/N;
        ans += num;

        a[0] %= N;
        for (int i = 1; i < N; i++) {
            a[i] += num;
        }

        if (a[1] < N) {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}