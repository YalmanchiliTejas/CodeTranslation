#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int main() {
    int n;cin>>n;
    int h=0;
    int ans=0;
    for(int i = 0;i < n;++i) {
        int t;
        cin>>t;
        if(t>=h)++ans;
        h=max(t,h);
    }
    cout<<ans<<endl;
    return 0;
}
