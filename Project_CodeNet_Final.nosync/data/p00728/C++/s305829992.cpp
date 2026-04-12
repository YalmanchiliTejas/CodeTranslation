#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int n, total;
    int s[1000];
    while (true) {
        cin >> n;
        if (n == 0) {
            return 0;
        }
        for (int i=0; i<n; i++) {
            cin >> s[i];
        }
        sort(s, s+n);
        total = accumulate(s+1, s+n-1, 0);
        cout << total/(n-2) << endl;
    }
}