#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m=pow(10,9)+7;
int main(){
    int n;
    cin >> n;
    ll a[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum+=a[i];
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        sum-=a[i];
        ans+=(sum%m*a[i]%m)%m;
    }
    cout << ans%m << endl;
}