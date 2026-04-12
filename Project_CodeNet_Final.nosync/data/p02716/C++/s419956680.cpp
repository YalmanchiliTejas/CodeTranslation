#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

int main(){
    ll n;
    cin>>n;
    vll a(n);
    rep(i,n) cin>>a[i];
    vll left(n,-1e10);
    vll right(n,-1e10);
    vll mid(n,-1e10);
    if(n%2==0){
        left[0]=a[0];
        right[0]=a[1];
        rep(i,n/2-1){
            left[i+1]=left[i]+a[i*2+2];
            right[i+1]=max(left[i],right[i])+a[i*2+3];
        }
        cout<<max({left[n/2-1],right[n/2-1]})<<endl;
    }
    else{
        left[0]=a[0];
        mid[0]=a[1];
        right[0]=a[2];
        rep(i,n/2-1){
            left[i+1]=left[i]+a[i*2+2];
            mid[i+1]=max(left[i],mid[i])+a[i*2+3];
            right[i+1]=max({left[i],mid[i],right[i]})+a[i*2+4];
        }
        cout<<max({left[n/2-1],mid[n/2-1],right[n/2-1]})<<endl;
    }
}
