#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    long long a,b,c,x,y,d;
    cin>>a>>b>>c>>x>>y;
    if(a+b>=c*2){
        if(x>=y){
            d=min(c*2*x,c*2*y+a*(x-y));
        }else{
            d=min(c*2*y,c*2*x+b*(y-x));
        }
    }else{
        d=a*x+b*y;
    }
    cout<<d<<endl;
}
