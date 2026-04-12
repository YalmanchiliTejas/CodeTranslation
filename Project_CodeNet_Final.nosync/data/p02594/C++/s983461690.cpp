/* Written in FCP - alpha version */
#ifdef false
/* Original code */
$i
X:int
$p
if X >= 30 {
    <<"Yes"
}{
    <<"No"
}
#endif
/* Transpiled code */

#include <bits/stdc++.h>

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
#define mp make_pair
#define fi first
#define se second

using namespace std;

using str = string;
using uint = unsigned int;
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vc = vector<char>;
using vll = vector<ll>;
using vvi = vector<vector<int>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<str>;
using vvs = vector<vector<str>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    for (int i = 0; i < sz(t); i++) {
        s << t[i] << (i == sz(t) - 1 ? "" : " ");
    }
    return s;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
        int X;
cin >> X;
if (X >= 30) {
    cout <<"Yes";
} else {
    cout <<"No";
};
        goto end_tc_label;
        end_tc_label:;
    
}
