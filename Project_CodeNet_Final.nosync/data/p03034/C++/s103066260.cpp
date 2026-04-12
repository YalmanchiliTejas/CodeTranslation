#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;

int main() {
    ll n;
    cin >> n;
    vector<ll> s(n);
    rep(i,n) cin >> s[i];
    ll ans=0,o;
    rep(i,n-1){
        o=0;
        set<int> ss;
        rep(j,inf){
            if ((i+1)*(j+1)>n-1) break;
            if (ss.find((i+1)*(j+1))!=ss.end() || ss.find(n-1-(i+1)*(j+1))!=ss.end()) break;
            if (n-1-(i+1)*(j+1)==(i+1)*(j+1)) break;
            if (n-1-(i+1)*(j+1)<=i+1) break;
            o=o+s.at((i+1)*(j+1))+s.at(n-1-(i+1)*(j+1));
            ans=max(ans,o);
            ss.insert(n-1-(i+1)*(j+1));
            ss.insert((i+1)*(j+1));
        }
    }
    cout << ans << endl;
}