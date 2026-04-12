#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

int main() {
    long n, k, ans;
    string str;
    cin >> str >> k;
    n = str.length();
    if(k == 1) {
        ans = (str.at(0) - '0') + (n - 1) * 9;
    } else if(k == 2) {
        ans = (n - 1) * (n - 2) * 81 / 2;
        ans = max(ans, 0l);
        bool flag = true;
        rep(i, n - 1) {
            if(flag) ans += (str.at(0) - '1') * 9 + (str.at(i + 1) - '0');
            else ans += (str.at(0) - '0') * 9;
            if(str.at(i + 1) != '0') flag = false;
        }
        ans = max(ans, 0l);
    } else {
        ans = (n - 1) * (n - 2) * (n - 3) * 243 / 2;
        ans = max(ans, 0l);
        bool flag = true, fflag = true;
        rep(i, n - 2) {
            fflag = true;
            rep(j, n - 1) {
                if(i >= j) continue;
                if(flag) {
                    if(fflag) ans += (str.at(0) - '1') * 81 + max((long)((str.at(i + 1) - '1') * 9 + (str.at(j + 1) - '0')), 0l);
                    else ans += (str.at(0) - '1') * 81 + (str.at(i + 1) - '0') * 9;
                    if(str.at(j + 1) != '0') fflag = false;
                } else {
                    ans += (str.at(0) - '0') * 81;
                }
            }
            if(str.at(i + 1) != '0') flag = false;
        }
        ans = max(ans, 0l);
    }
    cout << ans << endl;
}