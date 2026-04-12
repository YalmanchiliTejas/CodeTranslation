#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int,int>;
const int MOD = 1000000007;

int main() {
    int x,y,z;
    cin>>x>>y>>z;
    x-=z;
    ll ans=x/(y+z);
    cout<<ans<<endl;
}
