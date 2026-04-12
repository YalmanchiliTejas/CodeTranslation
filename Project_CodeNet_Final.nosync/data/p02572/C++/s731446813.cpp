#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    ll n;
    cin>>n;
    vector<ll> a(n), l(n+1);
    l[0]=0;
    ll sum=0;
    rep(i,0,n){
        cin>>a[i];
        sum+=a[i]%INF;
        l[i+1]=l[i]+a[i];
    }

    ll ans=0;
    rep(i,0,n){
        ll sum=(l[n]-l[i+1])%INF;
        ans+=a[i]*sum;
        ans%=INF;
    }
    cout<<ans<<endl;
    return 0;
}