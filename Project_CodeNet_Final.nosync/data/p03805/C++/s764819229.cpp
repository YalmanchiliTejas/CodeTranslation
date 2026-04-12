#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int n, m; cin >> n >> m;
    int a[m], b[m];
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
    }
    int c[n];
    for (int i = 0; i < n; ++i) {
        c[i] = i + 1;
    }
    int cnt = 0;
    do {
        int flg = 0;
        /*
        for (int i = 0; i < n; ++i) {
            cout << c[i] << " ";
            if (i == n - 1) cout << endl;
        }*/
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if ((c[i - 1] == a[j] && c[i] == b[j]) || (c[i - 1] == b[j] && c[i] == a[j])) {
                    break;
                }
                if (j == m - 1) {
                    flg++;
                }
            }
            if (flg) {
                break;
            }
            if (i == n - 1) {
                cnt++;
            }
        }
    } while (next_permutation(c, c + n) && c[0] == 1);
    cout << cnt << endl;
    return 0;
}
