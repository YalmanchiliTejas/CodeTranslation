#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int n, k;
    string s;
    cin >> n >> s >> k;
    char t = s[k - 1];
    string ans;
    rep(i, s.size()) {
        if (s[i] == t) {
            ans += s[i];
        }
        else {
            ans += '*';
        }
    }
    cout << ans << endl;
    return 0;
}
