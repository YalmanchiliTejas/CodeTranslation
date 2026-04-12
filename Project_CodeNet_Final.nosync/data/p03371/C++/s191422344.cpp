#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
int main(){
    ll a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll min=10000000000;
    for(ll i=0;i<=max(x,y)*2;i+=2){
        ll pr=c*i+a*max((ll)0,x-i/2)+b*max((ll)0,y-i/2);
        if(min>pr){
            min=pr;
        }
    }
    cout<<min<<endl;
    return 0;
}