#include<bits/stdc++.h>
using namespace std;

void solve(){
    // int n;
    // cin>>n;
    // int a[n];
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }

}
long long mul(long long a, long long b, long long m){
    long long res=0;
    while(b){
        if(b&1)
            res=(res+a)%m;
        a=(2*a)%m;
        b=b/2;

    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // int t;
    // cin>>t;
    // while(t--){
    //     solve();
    // }
    int n;
    cin>>n;
    long long m=1e9+7;
    long long a[n];
    long long prefixsum[n];
    cin>>a[0];
    prefixsum[0]=a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        prefixsum[i]=prefixsum[i-1]+a[i];
    }
    long long ans=0;
    for(int i=0;i<n-1;i++){
        ans+=mul(a[i],prefixsum[n-1]-prefixsum[i],m);
        ans=ans%m;
    }
    cout<<ans;

}