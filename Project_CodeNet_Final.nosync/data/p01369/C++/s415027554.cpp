#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
#define _ << " " <<
#define all(X) (X).begin(), (X).end()
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define Ti4 tuple<int, int, int, int>
#define Tlll tuple<ll, ll, ll>
#define PI 3.141592653589793

int main() {
    string s, t = "yuiophjklnm";
    bool b[200] = {};
    for (int i = 0; i < t.size(); i++) b[t[i]] = 1;
    
    while (cin >> s) {
        if (s == "#") return 0;
        int ans = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (b[s[i]] ^ b[s[i + 1]]) ans++;
        }
        cout << ans << endl;
    }
}

