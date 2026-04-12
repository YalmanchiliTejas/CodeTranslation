//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1147&lang=jp

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) return 0;

        vector<int> vt(n);
        for (int i = 0; i < n; ++i) {
            cin >> vt[i];
        }
        
        sort(vt.begin(), vt.end());
        cout << accumulate(vt.begin() + 1, vt.end() - 1, 0) / (n - 2) << endl;
    }
}


/*
 *
 */
