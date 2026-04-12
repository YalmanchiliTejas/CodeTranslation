#include <iostream>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

int main(){
    int a,b,c,x,y;
    ll ans=100000000000;
    cin>>a>>b>>c>>x>>y;
    for(int i=0;i<200001;i+=2){
        ll v=c*i;
        v+=max(0,x-(i/2))*a;
        v+=max(0,y-(i/2))*b;
        ans=min(ans,v);
    }
    cout<<ans<<endl;
}