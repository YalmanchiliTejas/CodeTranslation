#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int mx = 0;
    int h;
    int a = 0;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (mx <= h) {
            a++;
            mx = h;
        }
    }
    cout << a << endl;
}
