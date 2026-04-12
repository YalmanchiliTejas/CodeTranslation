#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <numeric>
using namespace std;
#define ll long long
#define rep(i,l,r) for(ll i=(l);i<(r);i++)
int main(void){
    int a,b,c,x,y,cnt=0;
    cin>>a>>b>>c>>x>>y;
    c*=2;
    if(a+b>c){
        int mn=min(x,y);
        cnt+=mn*c;
        x-=mn;
        y-=mn;
    }
    if(a>c){
        cnt+=x*c;
        x=0;
    }
    if(b>c){
        cnt+=y*c;
        y=0;
    }
    cnt+=x*a+y*b;
    cout<<cnt<<endl;
    return 0;
}