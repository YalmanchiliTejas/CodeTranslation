#include <bits/stdc++.h>
using namespace std;
int main(){
    long a,b,c,x,y,tong,tien=0,min,banh=0,banh1=0;
    cin>>a>>b>>c>>x>>y;
    if ((a+b)/2>=c) {
        int Min=(x>y) ? y : x;
        banh=Min*c*2;
        if(x>Min) banh+=(x-Min)*a;
        if(y>Min) banh+=(y-Min)*b;
        int M=(x>y) ? x : y;
        banh1=2*c*M;
    }
    else banh=a*x+b*y;
    if(banh1==0 || banh1>banh) cout<<banh;
    else cout<<banh1;
    return 0;
}