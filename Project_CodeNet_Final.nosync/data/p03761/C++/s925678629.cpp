#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <map>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s.at(i);
    vector<vector<int>> a(n, vector<int> (26));
    vector<int> mini(26, INF);
    rep(i, n) {
        rep(j, s.at(i).size()) {
            a.at(i).at(s.at(i).at(j) - 'a')++;
        }
    }
    rep(i, 26) {
        rep(j, n) {
            mini.at(i) = min(mini.at(i), a.at(j).at(i));
        }
    }
    string ans;
    rep(i, 26) {
        while(mini.at(i) > 0) {
            ans.push_back('a' + i);
            mini.at(i)--;
        }
    }
    cout << ans << endl;
}