#include <iostream>
#include<string>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,x,y,ans;
    cin>>a>>b>>c>>x>>y;
    if(x>y && (c*2)<a){
        ans=c*2*x;
    }else if(x<y && (c*2)<b){
        ans=c*2*y;
    }else if(c*2>a+b){
        ans=x*a+y*b;
    }else if(x>y){
        ans=y*c*2+(x-y)*a;
    }else{
        ans=x*c*2+(y-x)*b;
    }
    cout<<ans<<endl;
}