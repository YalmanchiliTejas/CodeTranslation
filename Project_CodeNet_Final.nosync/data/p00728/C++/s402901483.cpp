#include <iostream>
#include <vector>
#include <algorithm>
#define INF (int)1e9 + 7
using namespace std;

int main() {
    int n;
    while (cin >> n && n) {
        vector<int> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        sort(s.begin(), s.end());
        int sum = 0;
        for (int i = 1; i < n - 1; i++) {
            sum += s[i];
        }
        cout << sum / (n - 2) << endl;
    }
    return 0;
}
