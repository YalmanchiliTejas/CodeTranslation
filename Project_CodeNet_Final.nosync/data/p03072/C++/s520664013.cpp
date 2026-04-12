#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) REP(i, 0, n)
#define REP(i, x, n) for (int i = x; i < n; i++)
#define REP2(i, x, n) for (int i = x; i <= n; i++)
#define OP(x) cout << x << endl;
template<typename T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
typedef long long ll;

int main() {
    int n; cin >> n;
    vector<int> vec(n);
    rep(i, n) cin >> vec[i];

    int ans = 1;
    for(int i = 1; i < n; i++){
        bool flag = true;
        for(int j = i - 1; 0 <= j; j--){
            if(vec[i] < vec[j]){
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }
    OP(ans);
}
