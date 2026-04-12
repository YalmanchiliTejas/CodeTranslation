#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll ans=0;
    ll l=1,r=n-1;
    if(n%2==1){
        ll lx=a[0],ly=a[0];
        ll rx,ry;
        while(l<r){
            rx=a[r],ry=a[r-1];
            r-=2;
            ans+=rx-lx;
            ans+=ry-ly;
            lx=a[l],ly=a[l+1];
            l+=2;
            ans+=rx-lx;
            ans+=ry-ly;
        }
        rx=a[n-1],ry=a[n-1];
        l=0,r=n-2;
        ll sum=0;
        while(l<r){
            lx=a[l],ly=a[l+1];
            l+=2;
            sum+=rx-lx;
            sum+=ry-ly;
            rx=a[r],ry=a[r-1];
            r-=2;
            sum+=rx-lx;
            sum+=ry-ly;
        }
        ans=max(ans,sum);
    }else{
        ll lx=a[0],rx=a[n-1];
        ans+=rx-lx;
        ll ly,ry;
        r=n-2;
        while(l<r){
            ry=a[r],ly=a[l];
            ans+=ry-lx;
            ans+=rx-ly;
            l++;
            r--;
            if(l>=r) break;
            rx=a[r],lx=a[l];
            ans+=rx-ly;
            ans+=ry-lx;
            r--;
            l++;
        }
    }
    cout << ans << endl;
}