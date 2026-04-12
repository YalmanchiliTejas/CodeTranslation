/**
 * Dont raise your voice, improve your argument.
 * --Desmond Tutu
 */

#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
typedef long long ll;
#define int ll
#define fori(n) for(int i=0; i<int(n); i++)

#define cins(s) string s; cin>>s;
#define cini(i) int i; cin>>i;
#define cind(d) double d; cin>>d;
#define cinai(a, n) vi a(n); fori(n) { cin>>a[i]; }
#define cinas(s, n) vs s(n); fori(n) { cin>>s[i]; }
#define cinad(a, n) vd a(n); fori(n) { cin>>a[i]; }

typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<string> vs;

/* How to include "exactly n/2 elements" ?
 * Like knapsack?
 * maxval(i,k,bool)=max(a[i]+maxval(i+1, k-1, true), maxval(i+1, k, false));
 */
void solve() {
    cini(n);
    cinai(a,n);

    map<pii, int> memo;
    const int INF=1e18;
    function<int(int,int)> maxval=[&](int i, int k) {
        if(k==0)
            return 0LL;

        int need=(k-1)*2+1;
        if(i+need>n)
            return -INF;

        pii key={i,k};
        auto it=memo.find(key);
        if(it!=memo.end())
            return it->second;
            
        return memo[key]=max(a[i]+maxval(i+2, k-1), maxval(i+1, k));
    };

    int ans=maxval(0, n/2);
    cout<<ans<<endl;
}

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    solve();
}

