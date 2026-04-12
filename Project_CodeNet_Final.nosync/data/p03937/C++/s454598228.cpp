#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define otp(n) cout << n;
#define ct(n) cout << n << endl;
#define cts(n) cout << n << " ";
#define cte cout << endl;
#define ctv(v) rep(i,(v).size()) ct(v[i])
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define repo(i,o,n) for(int i=o;i<n;i++)
#define repm(i,n) for(int i=n-1;i>=0;i--)
#define repv(i,v) for(int i=0;i<(v).size();i++)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sperase(v,n) (v).erase(remove(all(v), n), (v).end());
#define vdelete(v) (v).erase(unique(all(v)), (v).end());
#define pb(n) push_back(n);

int h,w,cnt;
string s;

main() {
    cin >> h >> w;
    rep(j,h) {
        cin >> s;
        rep(i,w) if (s[i]=='#') cnt++;
    }
    if (cnt==h+w-1) ct("Possible")
    else ct("Impossible"
    )
}
