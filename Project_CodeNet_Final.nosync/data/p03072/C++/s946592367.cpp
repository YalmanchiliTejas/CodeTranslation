#include <bits/stdc++.h>
using namespace std;
#define int long long




signed main(){
    int n;
    cin>>n;
    int h[n],maxh=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>h[i];
        if(maxh<=h[i])ans++;
        maxh=max(maxh,h[i]);
    }
    cout<<ans;
    return 0;
}