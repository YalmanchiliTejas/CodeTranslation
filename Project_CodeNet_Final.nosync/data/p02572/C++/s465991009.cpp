#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    long long ans=0,k=0,t;
    vector<long long> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<n; i++){
        ans+=a[i];
        ans%=(1000000007*2);
        t=a[i]*a[i];
        t%=(1000000007*2);
        k+=t;
        k%=(1000000007*2);
    }
    ans*=ans;
    ans%=(1000000007*2);
    if(ans-k<0) ans+=(1000000007*2);
    ans=(ans-k);
    ans%=(1000000007*2);
    ans/=2;
    cout << ans;
}