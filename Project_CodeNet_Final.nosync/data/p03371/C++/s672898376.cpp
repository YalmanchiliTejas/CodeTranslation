#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,c,x,y; cin >>a>>b>>c>>x>>y;
    
    ll result=pow(10,10);
    for(int ci=0;ci<=max(x,y)*2;ci++){
        if(ci%2) continue;
        ll sum=0;
        sum=c*ci+a*(max(x-ci/2,0))+b*(max(0,y-ci/2));
        //cout<<sum<<endl;
        result=min(result,sum);
    }
    
    cout<<result<<endl;
}