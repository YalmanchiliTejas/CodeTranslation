#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int A,B,C,X,Y,a,b,c,d,e,ans;
    cin>>A>>B>>C>>X>>Y;
    a=A*X+B*Y;
    b=max(X,Y)*2*C;
    ans=min(a,b);
    c=min(X,Y)*C*2;
    if(X<Y){
        d=(Y-X)*B;
        c=c+d;
    }else{
        e=(X-Y)*A;
        c=c+e;
    }
    cout<<min(ans,c)<<endl;
    
}
