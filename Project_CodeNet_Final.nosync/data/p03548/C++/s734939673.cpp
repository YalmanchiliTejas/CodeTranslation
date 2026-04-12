#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int X,Y,Z;
    scanf("%d%d%d",&X,&Y,&Z);
    int ans=0;
    if(X==Y+2*Z){cout<<1<<endl;}
    else if(X<Y+2*Z){cout<<0<<endl;}
    else if(X>Y+2*Z){cout<<(X-(Y+2*Z))/(Y+Z)+1<<endl;}
    return 0;
}
