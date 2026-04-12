#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
    ll X,Y,Z;
    cin>>X>>Y>>Z;
    ll ans=1;
    X-=(Y+2*Z);
    ans+=X/(Y+Z);
    cout<<ans<<endl;
}
