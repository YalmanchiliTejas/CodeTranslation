#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    int s[n]; for (int i = 0; i < n; i++) cin >> s[i];
    long long ans = 0;
    for (int d = 1; d < n-1; d++) {
        bool stop = (n-1)%d==0;
        int m = 0, a = n-1;
        long long sum = 0;
        for (;;) {
            m += d; a -= d;
            if ((stop && m >= a) || a <= d) break;
            else sum += s[m] + s[a];
            // cerr << d << ' ' << m << ' ' << a << ' ' << sum << endl;
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
