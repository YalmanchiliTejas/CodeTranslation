#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define dump(val) cerr << __LINE__ << ":\t" << #val << " = " << (val) << endl

using namespace std;

typedef long long int lli;

int main() {
    string s;
    while (cin >> s, s != "#") {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int W = -1;
        vector<bool> v;
        REP (pos, 0, s.size()) {
            if (s[pos] == 'b') v.push_back(true);
            else if (s[pos] != '/') {
                REP (_, 0, s[pos] - '0') v.push_back(false);
            } else if (W == -1) {
                W = v.size();
            }
        }
        v[(a - 1) * W + b - 1] = false;
        v[(c - 1) * W + d - 1] = true;
        for (int ok = 0, H = 0; H < v.size() / W; H++, ok = 1) {
            if(ok) cout << '/' ;
            int cnt = 0;
            REP (i, 0, W) {
                if (v[H * W + i]) {
                    if (cnt) cout << cnt;
                    cout << 'b';
                    cnt = 0;
                }
                else cnt++;
            }
            if (cnt) cout << cnt;
        }
        cout << endl;
    }
    return 0;
}
