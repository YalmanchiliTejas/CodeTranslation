# include <iostream>
# include <algorithm>
using namespace std;

int main() {
    int n; cin >> n;
    while (n != 0) {
        int max_s = 0, min_s = 1000, sum_s = 0;
        for (int i = 0; i < n; ++i) {
            int s; cin >> s;
            max_s = max(max_s, s);
            min_s = min(min_s, s);
            sum_s += s;
        }
        int ans = (sum_s - max_s - min_s) / (n - 2);
        cout << ans << endl;
        
        cin >> n;
    }
    return 0;
}
