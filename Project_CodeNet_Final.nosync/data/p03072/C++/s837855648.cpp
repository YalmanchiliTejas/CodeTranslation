#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int last;
    int cur, ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        if (i == 0) {
            ++ans;
            last = cur;
        }
        else {
            if (cur < last) {
                continue;
            }
            ++ans;
            last = cur;
        }
    }
    cout << ans;
    return 0;
}