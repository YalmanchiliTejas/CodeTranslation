#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define countof(array) (sizeof(array) / sizeof(array[0]))
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,n,s) for(int i = s; i < (n); ++i)
#define rsrep(i,n,s) for(int i = (n)-1; i >= s; --i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define aall(a) (a), (a)+countof(a)//for array sorting
#define raall(a) (a), (a)+countof(a), greater<>()
#define show(x) cout<<#x<<" = "<<x<<endl;
#define vfind(v, a) find(all(v), a) != v.end()
#define yn(f) { if (f) puts("YES"); else puts("NO"); }
#define yns(f) { if (f) puts("Yes"); else puts("No"); }
#define show_ary(...) { cout<<#__VA_ARGS__<<" = "; for (const auto& x : (__VA_ARGS__)) { cout<<x<<" "; } cout<<endl; }
#define out_ary(...) { for (const auto& x : (__VA_ARGS__)) { cout<<x<<" "; } cout<<endl; }
#define argmax(v) distance((v).begin(), max_element(all(v)))
#define argmin(v) distance((v).begin(), min_element(all(v)))
#define vmax(v) *max_element(all(v))
#define vmin(v) *min_element(all(v))
typedef long long int ll;
typedef vector<int> vint;
typedef vector<string> vstr;
typedef vector<bool> vbool;
typedef vector<vint> vvint;
typedef vector<vstr> vvstr;
const ll LINF = 2000000000000000000ll;
const int INF = 1000000100;
const ll MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    vstr s(n);
    rep(i, n) cin >> s[i];
    string que;
    que = s[0];
    cout << endl;
    srep(i, n, 1) {
        string n_que;
        for (char sx : s[i]) {
            auto f = find(all(que), sx);
            if (f != que.end()) {
                n_que.push_back(sx);
                int idx = distance(que.begin(), f); 
                que.erase(idx, 1);
            } else {
                continue;
            }
        }
        que = n_que;
    }
    if (que.size() == 0) cout << endl;
    else {
        sort(all(que));
        cout << que << endl;
    }
    return 0;
}