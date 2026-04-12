#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int result = 0;
    vector<int> h(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    int tmp = h[0];
    for (int i= 0; i < N; i++) {
        if (i == 0) {
            result += 1;
            tmp = h[0];
            continue;
        }
        if (tmp <= h[i]) {
            tmp = h[i];
            result++;
        }
    }
    cout << result << endl;
    return 0;
}