#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    ll n; cin>>n;
    if(n%2==0){
        vector<ll> a(n);
        rep(i,n) cin>>a[i];
        ll tmp=0;
        for(ll i=0; i<n; i+=2){
            tmp+=a[i];
        }
        vector<ll> right(n/2+1);
        for(ll i=0; i<n/2; i++){
            if(i==0) right[n/2-1]=a[n-1]-a[n-2];
            else right[n/2-1-i]=right[n/2-i]+a[n-1-2*i]-a[n-2-2*i];
        }
        rep(i,n/2){
            //chmax(left[i+1], left[i]);
            chmax(right[n/2-1-i], right[n/2-i]);
        }
        ll res=tmp;
        chmax(res, tmp+right[0]);
        for(ll i=0; i<n/2; i++){
            chmax(res, tmp+right[i+1]);
        }
        //rep(i,n/2+1) cout<<right[i]<<' '; cout<<endl;
        //rep(i,n/2) cout<<left[i]<<' '; cout<<endl;
        cout<<res<<endl;
    }else{
        vector<ll> a(n);
        rep(i,n) cin>>a[i];
        ll tmp=0;
        for(ll i=1; i<n; i+=2){
            tmp+=a[i];
        }
        vector<ll> left(n/2), right(n/2+1);
        for(ll i=0; i<n/2; i++){
            if(i==0) left[0]=a[0]-a[1];
            else left[i]=left[i-1]+a[2*i]-a[2*i+1];

            if(i==0) right[n/2-1]=a[n-1]-a[n-2];
            else right[n/2-1-i]=right[n/2-i]+a[n-1-2*i]-a[n-2-2*i];
        }
        rep(i,n/2){
            //chmax(left[i+1], left[i]);
            chmax(right[n/2-1-i], right[n/2-i]);
        }
        ll res=tmp;
        chmax(res, tmp+right[0]);
        for(ll i=0; i<n/2; i++){
            chmax(res, tmp+left[i]+right[i+1]);
        }
        //rep(i,n/2+1) cout<<right[i]<<' '; cout<<endl;
        //rep(i,n/2) cout<<left[i]<<' '; cout<<endl;
        cout<<res<<endl;
    }
    return 0;
}