#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n)cin >> a[i];
    sort(ALL(a));

    ll ans = 0;
    rep(i, n/2)ans+=2*(a[n-1-i]-a[i]);
    if(n%2 == 0)ans+=a[n/2-1], ans-=a[n/2];
    else ans += max(a[n/2]-a[n/2+1], -a[n/2]+a[n/2-1]);
    
    cout << ans << endl;
}