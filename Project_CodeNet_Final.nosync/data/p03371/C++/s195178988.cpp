#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(void){
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int cost=0,minXY;
    minXY=min(X,Y);
    //min(A,B)枚について
    if(A+B>2*C)cost+=2*C*minXY;
    else cost+=(A+B)*minXY;
    if(X==Y){cout<<cost<<endl; return 0;}
    //残りについて
    if(X>Y){
        if(A>2*C) cost+=(X-minXY)*2*C;
        else cost+=(X-minXY)*A;
    }
    else{
        if(B>2*C) cost+=(Y-minXY)*2*C;
        else cost+=(Y-minXY)*B;
    }
    cout<<cost<<endl;
    return 0;
}
