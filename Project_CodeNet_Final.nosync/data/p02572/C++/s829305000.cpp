#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define For(i,n) for(int i = 0; i < (int) n; ++i)
#define Rep(i,n) for(int i = 1; i <= (int) n; ++i)
#define ll long long
#define lld long double
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define ar array
#define INF 1e18;
#define all(v) (v).begin(),(v).end()
const int N=2e5+1,mod=1e9+7;


void solve(){
    ll n,a[N];
    cin>>n;
    ll s=0;
    ll ans=0;
    for(int i=0;i<n;i++)cin>>a[i],s+=a[i];
    for(int i=0;i<n;i++){
        s-=a[i];
        ans=(ans+a[i]%mod*(s%mod))%mod;
    }
    cout<<ans%mod;


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while(t--){
        //cout<<"Case #"<<a<<": ";
        solve();
        //a+=1;
    }
}
