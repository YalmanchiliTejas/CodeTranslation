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
#define show_pair(...) cout<<#__VA_ARGS__<<" = "<<endl; for (const auto& x : (__VA_ARGS__)) { cout<<"  "<<x.fi<<" : "<<x.se<<endl; }
#define out_ary(...) { for (const auto& x : (__VA_ARGS__)) { cout<<x<<" "; } cout<<endl; }
#define argmax(v) distance((v).begin(), max_element(all(v)))
#define argmin(v) distance((v).begin(), min_element(all(v)))
#define vmax(v) *max_element(all(v))
#define vmin(v) *min_element(all(v))
typedef long long int ll;
typedef pair<int, int> P;
typedef vector<P> vpair;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<double> vdouble;
typedef vector<string> vstr;
typedef vector<bool> vbool;
typedef vector<vint> vvint;
typedef vector<vll> vvll;
typedef vector<vstr> vvstr;
typedef vector<vbool> vvbool;
const ll LINF = 2000000000000000000ll;
const int INF = 1000000100;
const ll MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    vint a(n);
    rep(i, n) cin >> a[i];

    vll ans(2, 0);
    sort(all(a));
    
    deque<int> q;
    rep(i, n) q.push_back(a[i]);
    
    int l = q.front(), r = q.front();
    q.pop_front();
    bool flag = true;
    while(q.size() > 1) {
        if (flag) {
            ans[0] += abs(q.back() - l);
            l = q.back();
            q.pop_back();
            ans[0] += abs(q.back() - r);
            r = q.back();
            q.pop_back();
            flag = false;
        }
        else {
            ans[0] += abs(q.front() - l);
            l = q.front();
            q.pop_front();
            ans[0] += abs(q.front() - r);
            r = q.front();
            q.pop_front();
            flag = true;
        }
    }
    if (q.size() == 1) {
        ans[0] += max(abs(q.front() - l), abs(q.front() - r));
        q.pop_front();
    }

    
    rep(i, n) q.push_back(a[i]);
    
    l = q.back(), r = q.back();
    q.pop_back();
    flag = false;
    while(q.size() > 1) {
        if (flag) {
            ans[1] += abs(q.back() - l);
            l = q.back();
            q.pop_back();
            ans[1] += abs(q.back() - r);
            r = q.back();
            q.pop_back();
            flag = false;
        }
        else {
            ans[1] += abs(q.front() - l);
            l = q.front();
            q.pop_front();
            ans[1] += abs(q.front() - r);
            r = q.front();
            q.pop_front();
            flag = true;
        }
    }
    if (q.size() == 1) {
        ans[1] += max(abs(q.front() - l), abs(q.front() - r));
        q.pop_front();
    }

    cout << max(ans[0], ans[1]) << endl;
    return 0;
}