
/**
 * Dont raise your voice, improve your argument.
 * --Desmond Tutu
 */

#include <bits/stdc++.h>
using namespace std;

const bool ready = [](){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(12);
    return true;
}();

const double PI = acos(-1);
using ll= long long;
#define int ll
#define all(v) (v).begin(), (v).end()
#define fori(n) for(int i=0; i<int(n); i++)

#define cini(i) int i; cin>>i;
#define cins(s) string s; cin>>s;
#define cind(d) double d; cin>>d;
#define cinai(a,n) vi a(n); fori(n) { cin>>a[i]; }
#define cinas(s,n) vs s(n); fori(n) { cin>>s[i]; }
#define cinad(a,n) vd a(n); fori(n) { cin>>a[i]; }

using pii= pair<int, int>;
using pdd= pair<double, double>;
using vd= vector<double>;
using vb= vector<bool>;
using vi= vector<int>;
using vvi= vector<vi>;
using vs= vector<string>;

#define endl "\n"

const int MOD=1e9+7;
void solve() {
    cini(n);
    cinai(a,n);

    vi pre(n+1);
    for(int i=1; i<=n; i++) 
        pre[i]=pre[i-1]+a[i-1];

    int ans=0;
    for(int i=0; i<n; i++) {
        int sum=(pre[n]-pre[i+1])%MOD;
        int prod=(a[i]*sum)%MOD;
        ans=(ans+prod)%MOD;
    }
    cout<<ans<<endl;
}

signed main() {
    solve();
}

// FIRST THINK, THEN CODE
// DO NOT JUMP BETWEEN PROBLEMS
