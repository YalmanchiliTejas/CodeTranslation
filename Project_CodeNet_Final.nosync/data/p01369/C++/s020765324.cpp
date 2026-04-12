#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;

const string lefth = "qwertasdfgzxcvb";
const string righth = "yuiophjklnm";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        string s; cin >> s;
        if (s=="#") break;

        int ans = 0;
        int state = 0;
        for(auto c: s) {
            if (state == 0) {
                if (count(all(lefth), c)) state = -1;
                else state = 1;
                continue;
            }
            if (count(all(lefth), c) && state==1) {
                ans++; state=-1;
            }
            else if (count(all(righth), c) && state==-1) {
                ans++; state=1;
            }
        }
        cout << ans << endl;
    }
}
