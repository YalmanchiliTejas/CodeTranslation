#include <iostream>
#include <algorithm>
using namespace std;
int n;
int main() {
    cin >> n;
    int best = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        if (height >= best) {
            best = height;
            ++ans;
        }
    }
    cout << ans;
}