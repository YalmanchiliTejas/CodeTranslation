#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=100000000000000000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a.at(i);
    ll ans=0;
    while(true){
        ll s=0;
        rep(i,n) s+=a.at(i)/n;
        rep(i,n){
            ll c=a.at(i);
            a.at(i)-=(a.at(i)/n)*n;
            a.at(i)+=s-c/n;
        }
        ans+=s;
        bool u=true;
        rep(i,n){
            if (a.at(i)>n-1) u=false;
        }
        if (u) break;
    }
    cout << ans << endl;

}
