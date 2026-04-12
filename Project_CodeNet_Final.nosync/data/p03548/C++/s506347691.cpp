#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int x,y,z;
    cin>>x>>y>>z;
    int ans=x/(z+y);
    if(x%(z+y)<z)cout<<ans-1<<endl;
    else cout<<ans<<endl;
}