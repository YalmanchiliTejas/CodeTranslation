#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin >> n >> k;
    if(k==0){
        cout << n*n << endl;
        return 0;
    }
    ll ans=0;
    for(ll i=k+1;i<=n;i++){
        ans+=n/i*(i-k)+max(0LL,n%i-k+1);
    }
    cout << ans << endl;
}