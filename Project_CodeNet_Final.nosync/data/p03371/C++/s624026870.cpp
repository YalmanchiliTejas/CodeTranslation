#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int A,B,C,X,Y; cin>>A>>B>>C>>X>>Y;
    ll ans=INF;
    rep(i,max(X,Y)+1){
        if(ans>2*C*i+A*max(0,X-i)+B*max(0,Y-i))ans=2*C*i+A*max(0,X-i)+B*max(0,Y-i);
    }
    cout<<ans<<endl;
    return 0;
}