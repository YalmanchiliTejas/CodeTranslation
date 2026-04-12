#include <iostream>
using namespace std;
int a,b,c,x,y,d,ans,z;
int main(void){
    cin>>a>>b>>c>>x>>y;
    d=min(x,y);
    z=max(x,y);
    if(a+b>2*c){
        ans=d*2*c+(x-d)*a+(y-d)*b;
    }
    else ans=a*x+b*y;
    cout<<min(ans,2*z*c)<<endl;
}
