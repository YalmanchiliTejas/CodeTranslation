#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int a,b,c;
    int x,y;
    cin>>a>>b>>c>>x>>y;
    int v=0;
    if(2*c<=a+b){
        v+=c*2*min(x,y);
        if(x>y){
            if(2*c*(x-y)<a*(x-y))
                v+=2*c*(x-y);
            else
                v+=a*(x-y);
        }
        else{
            if(2*c*(y-x)<b*(y-x))
                v+=2*c*(y-x);
            else
                v+=b*(y-x);
        }
    }
    else{
        v=(a+b)*min(x,y);
        if(x>y){
            if(2*c*(x-y)<a*(x-y))
                v+=2*c*(x-y);
            else
                v+=a*(x-y);
        }
        else{
            if(2*c*(y-x)<b*(y-x))
                v+=2*c*(y-x);
            else
                v+=b*(y-x);
        }
    }
    printf("%d\n",v);
    // insert code here...
    //std::cout << "Hello, World!\n";
    return 0;
}
