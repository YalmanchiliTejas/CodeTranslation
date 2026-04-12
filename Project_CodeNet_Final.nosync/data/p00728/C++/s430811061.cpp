#include <bits/stdc++.h>

using namespace std;

int main() {

    int n;

    while(cin >> n, n) {

        int s[n];
        int ans = 0;

        for(int i = 0; i < n; ++i) {
            cin >> s[i];
        }

        sort(s, s + n);

        for(int i = 1; i < n - 1; ++i) {
            ans += s[i];
        }

        cout << ans / (n - 2) << endl;

    }

}