#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int r,g,b;cin>>r>>g>>b;
    if((10*g+b)%4)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}