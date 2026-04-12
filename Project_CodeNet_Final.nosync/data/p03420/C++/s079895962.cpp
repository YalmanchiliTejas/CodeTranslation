#include <bits/stdc++.h>

using namespace std;

int INF=1e9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;
    cin>>n>>k;
    long long ans=0;
    for(int i=k+1;i<=n;i++){
        ans+=(i-k)*(n/i);
        int m=n%i;
        if(k!=0)ans+=max(0,m-k+1);
        else ans+=max(0,m-k);
    }

    cout<<ans<<endl;
}