#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for( i=a;i<b;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const ll MOD=1e9+7;



int main() {
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<int> alp(26,100);
    rep(i,n) {
        vector<int> talp(26);
        rep(j,s[i].size()) {
            ++talp[s[i][j]-'a'];
        }
        rep(j,26) alp[j]=min(alp[j],talp[j]);
    }
    rep(i,26) {
        rep(j,alp[i]) cout << char(i+'a');
    }
    cout << endl;
    return 0;
}