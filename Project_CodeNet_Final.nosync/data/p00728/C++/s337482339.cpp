#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }


int main() {
    int n;
    while(1) {
        cin >> n;
        if(n == 0) break;
        vector<int> point(n, 0);
        for(int i = 0; i < n; ++i) cin >> point[i];
        sort(point.begin(), point.end());
        int sum = 0;
        for(int i = 1; i < n-1; ++i) sum += point[i];
        cout << sum/(n-2) << endl;
    }
}
