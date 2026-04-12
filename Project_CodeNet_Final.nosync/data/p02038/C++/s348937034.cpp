#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>
#include<iomanip>
#include<set>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rrep(i, st, n) for (int i = st; i < n; ++i)
using pii = pair<int, int>;
const int inf = 1e9 + 7;

int main() {
    int n; cin >> n;
    string bef;
    rep(i, n) {
        string s; cin >> s;
        if (i) {
            if (bef == "T" && s == "F") {
                s = "F";
            } else {
                s = "T";
            }
        }
        bef = s;
    }
    cout << bef << endl;
    
}





