#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int hs[n];
    for (auto i = 0; i < n; i++) {
        cin >> hs[i];
    }
    auto val = 0;
    for (auto i = 0; i < n; i++) {
        bool visible = true;
        for (auto j = 0; j < i; j++) {
            if (!(hs[j] <= hs[i])) {
                visible = false;
                break;
            }
        }
        if (visible) {
            val += 1;
        }
    }
    cout << val;
}