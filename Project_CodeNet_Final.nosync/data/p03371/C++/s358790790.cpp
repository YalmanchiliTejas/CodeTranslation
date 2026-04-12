#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;

    C*=2;

    long ans=0;

    if(A+B>C){
        ans=min(X,Y)*C;
        if(X==Y){}
        else if(X>Y&&A<=C)ans+=(X-Y)*A;
        else if(X<Y&&B<=C)ans+=(Y-X)*B;
        else{
            ans=max(X,Y)*C;
        }
    }else{
        ans=A*X+B*Y;
    }

cout<<ans<<endl;

}