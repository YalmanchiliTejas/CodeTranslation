#include <iostream>
#include<algorithm>
#include<sstream>
#include<stack>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<deque>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,n) for(int i = 0; i < n;i++)
#define ALL(a)  (a).begin(),(a).end()
const int MOD = 998244353;
const ll INF = (1LL << 60);
string s, t, u; ll n, m = 6, k, q, ans, sum =0,b,c; 
int main() {
    cin >> n;
    vector<int> a(26, 50);
    rep(i, n) {
        cin >> s; int sz = s.size();
        vector<int> tmp(26, 0);
        rep(i, sz) tmp[s[i] - 'a']++;
        rep(i, 26) a[i] = min(a[i], tmp[i]);
    }
    rep(i, 26) {
        char c = 'a' + i;
        rep(j, a[i]) {
            cout << c;
        }
    }puts("");
}