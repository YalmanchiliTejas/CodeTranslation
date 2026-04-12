#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s;
    cin >> s;

    int d[N + 2];
    bool check;
    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 1; j++) {
            d[1] = i;
            d[2] = j;

            for (int k = 3; k <= N; k++) {
                if (s[(k - 1) - 1] == 'o') {
                    if (d[k - 1] == 0) {
                        d[k] = d[k - 2];
                    } else {
                        d[k] = !d[k - 2];
                    }
                } else {
                    if (d[k - 1] != 0) {
                        d[k] = d[k - 2];
                    } else {
                        d[k] = !d[k - 2];
                    }
                }
            }

            d[0] = d[N];
            d[N + 1] = d[1];

            check = true;
            for (int k = 1; k <= N; k++) {
                if (d[k] == 0) {
                    if (s[(k - 1)] == 'o' && d[k - 1] != d[k + 1]) {
                        check = false;
                        break;
                    } else if (s[(k - 1)] == 'x' && d[k - 1] == d[k + 1]) {
                        check = false;
                        break;
                    }
                } else {
                    if (s[(k - 1)] == 'o' && d[k - 1] == d[k + 1]) {
                        check = false;
                        break;
                    } else if (s[(k - 1)] == 'x' && d[k - 1] != d[k + 1]) {
                        check = false;
                        break;
                    }
                }
            }

            if (check) {
                for (int i = 1; i <= N; i++) {
                    if (d[i]) {
                        cout << "W";
                    } else {
                        cout << "S";
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
