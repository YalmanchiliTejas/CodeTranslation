#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int b=1; b<=n; ++b){
        ans+=max(0,b-k)*(n/b);
        ans+=max(0,n%b-k+1);
    }
    if(k==0)ans-=n;
    cout<<ans<<endl;
    return 0;
}