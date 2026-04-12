#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> vi;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            vi.push_back(a);
        }

        sort(vi.begin(), vi.end());

        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            sum += vi[i];
        }

        cout << sum / (n - 2) << endl;
    }
}
