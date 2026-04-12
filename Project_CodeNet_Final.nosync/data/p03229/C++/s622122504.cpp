#include <bits/stdc++.h>
#define rep(i,n,m) for(int i=n;i<(int)(m);i++)
#define rrep(i,n,m) for(int i=((int)(n)-1);i>=m;i--)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using namespace std;
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,0,n)  cin>>a[i];
    sort(all(a));
    if(n%2==0){
        ll ans=0;
        rep(i,0,n/2) ans-=(ll)2*a[i];
        rep(i,n/2,n) ans+=(ll)2*a[i];
        ans-=a[n/2];
        ans+=a[n/2-1];
        cout<<ans<<endl;
    }
    else{
        ll ans=0;
        
        ll now=0;
        rep(i,0,n/2) now-=(ll)2*a[i];
        rep(i,n/2,n) now+=(ll)2*a[i];
        now-=a[n/2]+a[n/2+1];
        ans=max(ans,now);
        
        now=0;
        rep(i,0,n/2+1) now-=(ll)2*a[i];
        rep(i,n/2+1,n) now+=(ll)2*a[i];
        now+=a[n/2-1]+a[n/2];
        ans=max(now,ans);
        
        cout<<ans<<endl;
    }
}
