#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;
typedef long long ll;

int main(){
    int n, m;
    int ans = 0;
    cin >> n >> m;
    vector<int> x(n), a(m), b(m);
    for (int i = 0; i < n; i++) {
        x[i] = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }
    do {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (((x[i - 1] == a[j]) && (x[i] == b[j])) || ((x[i - 1] == b[j]) && (x[i] == a[j]))) {
                    cnt++;
				}
            }
        }
        if (cnt == n - 1) {
            ans++;
        }
    } while (next_permutation(x.begin() + 1, x.end()));

    cout << ans << endl;

    return 0;
}