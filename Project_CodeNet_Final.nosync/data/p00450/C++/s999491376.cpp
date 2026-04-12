#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pii pair<int, int>
#define eb emplace_back
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep3(i, l, n) for (int i = l; i < (n); ++i)
#define sz(v) (int)v.size()
#define inf (int)(1e9+7)
#define abs(x) (x >= 0 ? x : -(x))
#define ceil(a, b) a / b + !!(a % b)
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }
template<typename T> T pow(T a, int b) { return b ? pow(a * a, b / 2) * (b % 2 ? a : 1) : 1; }
template<typename T> T gcd(T a, T b) { if (b == 0) return a; return gcd(b, a % b); }

int main() {
    
    int n;
    while (cin >> n && n) {
        stack<pii> stk;
        
        int ans = 0;
        rep(i, n) {
            int a;
            cin >> a;
            // cout << "sz " << sz(stk) << endl;
            if (i == 0) stk.push(pii(a, 1));
            else if (i % 2 == 0) { // 0indexedで奇数番目
                pii b = stk.top();
                stk.pop();
                if (b.F == a) {
                    stk.push(pii(a, b.S + 1));
                } else {
                    stk.push(b);
                    stk.push(pii(a, 1));
                }
            } else {
                pii b = stk.top();
                stk.pop();
                // cout << b.F << " " << b.S << endl;
                
                if (b.F != a && sz(stk)) {
                    pii c = stk.top();
                    stk.pop();
                    stk.push(pii(a, b.S + c.S + 1));
                } else {
                    stk.push(pii(a, b.S + 1));
                }
                
            }
            
            // cout << stk.top().F << " " << stk.top().S << endl;
            
        }
        while (!stk.empty()) {
            pii a = stk.top();
            // cout << a.F << " " << a.S << endl;
            if (a.F == 0) ans += a.S;
            stk.pop();
        }
        
        cout << ans << '\n';
    }
}

