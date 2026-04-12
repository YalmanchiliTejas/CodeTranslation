#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int n,a,ans,pre;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        ans=(ans+(long long)pre*a)%mod;
        pre=(pre+a)%mod;
    }
    cout<<ans<<endl;

    return 0;
}