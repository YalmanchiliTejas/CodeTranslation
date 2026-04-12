#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
#define drep(i,cc,n) for(int i=cc;i>=n;--i)
typedef long long ll;
using namespace std;
const ll INF = 100000000000000000;

int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    ll hoge = 0;
    ll min = INF;
    rep(i,0,max(x,y)){
        ll d1 = x - i;
        ll d2 = y - i;
        if(d1<=0) d1 = 0;
        if(d2<=0) d2 = 0;
        hoge = 2*c*i+a*d1+b*d2;
        if(min>hoge) min = hoge;
    }
    cout<<min<<endl;
    return 0;
}