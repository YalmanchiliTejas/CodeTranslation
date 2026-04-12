#include <iostream>
#include <vector>
#include <algorithm>

#define REP(i,a,b) for(int i=int(a);i<int(b);i++)

using namespace std;

typedef long long int lli;

int main () {
    int n;
    cin >> n;
    vector<int> a(n);
    REP (i, 0, n) cin >> a[i];
    vector<int> ans(n);
    int sign = 1;
    int pos = n / 2;
    REP (i, 0, n) {
        ans[pos] = a[i];
        sign *= -1;
        pos += sign * (i + 1);
    }

    if (n % 2) {
        reverse(ans.begin(), ans.end());
    }
    REP (i, 0, n) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}
