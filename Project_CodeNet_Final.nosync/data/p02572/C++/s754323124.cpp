#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    ll n;
    ll m = 1000000007;
    cin >> n;
    ll a[n];
    ll p[n];
    for(int i=0;i<n;i++) cin >> a[i];
    ll res = 0;
    p[n-1]= a[n-1];
    for(int i=n-2;i>=0;i--){
        p[i] = (p[i+1]+a[i])%m;
    }
    for(int i=0;i<n-1;i++){
        res = (res%m + (a[i]*p[i+1])%m)%m;
    }
    cout << res;
}