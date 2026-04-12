#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        bool flag = 1;
        for (int j = 0; j < i; j++) {
            if (h[i] < h[j]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    }

    cout << ans << endl;
}