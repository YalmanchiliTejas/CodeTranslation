#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
    int N;
    cin >> N;
    vector<int> arr;
    int cur;
    for (int i = 0; i < N; i++) {
        cin >> cur;
        arr.push_back(cur);
    }

    int ans = 1;
    int prev = arr[0];
    for (int j = 1; j < N; j++) {
        bool ok(true);
        for (int k = 0; k < j; k++) {
            if (j != k && arr[j] >= arr[k]) {
            } else {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
