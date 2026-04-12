#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL << 60;
int main(void){
    int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
    long long ans=INF;
    for(int i=0;i<=max(x,y)*2;i++){
       int  xn=max(x-i/2,0);
       int  yn=max(y-i/2,0);
       //cout<<xn<<' '<<yn<<endl;
       long long tmp = xn*a+yn*b+i*c;
       //cout<<tmp<<endl;
       chmin(ans,tmp);
    }
    cout<<ans<<endl;
}