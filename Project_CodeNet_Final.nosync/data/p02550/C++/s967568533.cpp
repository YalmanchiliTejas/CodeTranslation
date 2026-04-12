

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

int step(int a, int m) {
    return (a*a)%m;
}

/* At less than m elements the seq repeats. */
void solve() {
    cini(n);
    cini(x);
    cini(m);

    vi first(m, -1);
    vi pre(2*m,0);

    int ans=0;
    for(int i=1; i<=n; i++) {
        if(first[x]>=0) {
            int loopsize=i-first[x];
            int loopsum=pre[i-1]-pre[first[x]-1];

            int loops=(n-i)/loopsize;
            ans+=loops*loopsum;
            i+=loops*loopsize;
            for(int j=0; j<(int)first.size(); j++)
                first[j]=-1;
        }

        if(i<(int)pre.size()) {
            pre[i]=pre[i-1]+x;
            first[x]=i;
        }

        ans+=x;
        x=step(x,m);
    }
    cout<<ans<<endl;
}

signed main() {
    solve();
}
