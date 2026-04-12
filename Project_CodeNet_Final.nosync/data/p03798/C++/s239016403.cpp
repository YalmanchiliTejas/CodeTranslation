#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>
#include<cassert>
#include<functional>
#include<unordered_map>
#include<deque>
#include<cmath>





using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;
const long double eps = 1e-5;
const ll INF = numeric_limits<int>::max();
const ll LINF = numeric_limits<ll>::max();
const ll mod = 1000 * 1000 * 1000 + 7;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> r(n);
    for (int i = 0; i < n; ++i) {
        r[i] = (s[i] == 'o');
    }
    r.push_back(r[0]);
    vector<int> x(n + 2);
    for (int m = 0; m < 4; ++m) {
        x[0] = m / 2;
        x[1] = m & 1;
        for (int i = 2; i < n + 2; ++i) {
            x[i] = r[i - 1] ^ x[i - 1] ^ x[i - 2];
        }
        if ((x[0] == x[n]) && (x[1] == x[n + 1])) {
            for (int i = 0; i < n; ++i) {
                if (x[i] == 0)
                    cout << "W";
                else cout << "S";
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;


}


//#define LOCAL

int main() {
    ios_base::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    solve();



#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif	
    return 0;
}
