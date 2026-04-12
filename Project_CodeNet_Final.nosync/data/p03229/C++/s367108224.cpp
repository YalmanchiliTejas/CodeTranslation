#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll ans=0,ans2=0;
    
    for(int i=(n/2)+2; i<n; i++) ans+=2*a[i];
    ans+=a[n/2];
    ans+=a[(n/2)+1];
    for(int i=0; i<n/2; i++) ans-=2*a[i];

    for(int i=0; i<n/2; i++) ans2+=2*a[n-i-1];
    for(int i=0; i<(n/2)-1; i++) ans2-=2*a[i];
    ans2-=a[n/2];
    ans2-=a[(n/2)-1];

    cout<<max(ans,ans2)<<endl;

}