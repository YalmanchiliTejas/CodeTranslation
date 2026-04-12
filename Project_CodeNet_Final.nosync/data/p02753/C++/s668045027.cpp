#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)
#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using ld = long double;

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

long int M = 1e+9+7;
int inf = 1e+9;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::setprecision(10);

    string s;
    cin >> s;
    if(s[0]==s[1] && s[1]==s[2]){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}