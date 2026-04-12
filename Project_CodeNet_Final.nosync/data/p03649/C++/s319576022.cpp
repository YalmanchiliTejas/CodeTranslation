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
    ll n;cin >> n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    bool f=true;
    ll ans=0;
    vector<ll> c(n);
    while(f){
        ll cnt=0;
        for(int i=0;i<n;i++){
            cnt+=a[i]/n;
        }
        for(int i=0;i<n;i++){
            a[i]=a[i]%n+cnt-a[i]/n;
        }
        ans+=cnt;
        bool g=true;
        for(int i=0;i<n;i++){
            if(a[i]>=n){
                g=false;
            }
        }
        if(g){
            f=false;
        }
    }
    cout << ans << endl;
}