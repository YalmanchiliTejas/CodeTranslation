#include<bits/stdc++.h>
using namespace std;
//type
typedef long long ll;
#define pii pair<int, int>;
#define vi vector<int>;
//x * y * 1.0 can cause overflow
//constant
#define inf (int)(1e9+7)
#define mod (ll)(1e9+7)
#define eps 1e-10
//omission
#define eb emplace_back
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define all(v) v.begin(), v.end()
//manip
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end(), v.end());
#define ceil(a, b) a / b + !!(a % b)
template<class T> T power(T a, T b)
{return b ? power(a * a % inf, b / 2) * (b % 2 ? a : 1) % inf : 1;}
#define LB(v, x) (int)(lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (int)(upper_bound(v.begin(), v.end(), x) - v.begin())
//loop
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep3(i, st, n) for (int i = st; i < n; ++i)
//algorithm
//double pointer, l start, how many adds, can be 0 -> init r = l, sum = 0
//bfs, not x, y, i, j
//not !(i % 2), i % 2 == 0


bool zero(string a) {
    if (a[0] == '0' && SZ(a) >= 2) return 0;
    return 1;
}

int main() {
    //cast caution
    //look constraints always
    cin.tie(0); ios::sync_with_stdio(false);
    
    
    string s; cin >> s;
    int ans = 0;
    rep(i, (1 << SZ(s))) {
        int cnt = 0;
        vector<int> v;
        rep(j, SZ(s)) if (i & (1 << j)) {cnt++; v.eb(j);}
        if (cnt != 3) continue;
        string a = s.substr(0, v[0]);
        string b = s.substr(v[0], v[1] - v[0]);
        string c = s.substr(v[1], v[2] - v[1]);
        string d = s.substr(v[2]); //v[2]以降
        if (SZ(a) == 0 || SZ(b) == 0 || SZ(c) == 0 || SZ(d) == 0) continue;
        if (stoi(a) > 255 || stoi(b) > 255 || stoi(c) > 255 || stoi(d) > 255) continue;
        if (zero(a) == 0 || zero(b) == 0 || zero(c) == 0 || zero(d) == 0) continue;
        
        //cout << a << " " << b << " " << c << " " << d << endl;
        ans++;
    }
    cout << ans << endl;
    
    
    
    
}


