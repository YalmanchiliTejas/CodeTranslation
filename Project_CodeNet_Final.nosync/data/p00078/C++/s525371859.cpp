#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        vector<vector<int>> v(n, vector<int>(n, 0));
        int y = n/2 + 1;
        int x = n/2;
        int cnt = 1;
        while (cnt <= n * n) {
            if (v[y][x] == 0) {
                v[y][x] = cnt;
                cnt ++;
                y = (y + 1) % n;
                x = (x + 1) % n;
            } else {
                y = (y + 1) % n;
                x = (x + n - 1) % n;
            }
        }
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                cout << setw(4) << v[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}