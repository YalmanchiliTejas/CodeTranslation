
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const long long INF = 2e18;
const long long MOD = 1e9+7;

#define sx(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i = 0; i < n; i++)
#define ALL(a) begin(a),end(a)

int main(void) {
    int n;
    while (cin >> n , n){
        vector<int> a(n);
        REP(i,n) cin >> a[i];
        sort(ALL(a));
        int sum = 0;
        for (int i=1; i<n-1; i++) {
            sum += a[i];
        }
        cout << sum/(n-2) << endl;
    }
    return 0;
}
