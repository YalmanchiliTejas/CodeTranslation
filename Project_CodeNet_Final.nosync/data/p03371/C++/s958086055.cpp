#include <iostream>
#include <algorithm>
int main() {
    int a,b,c,x,y,p=0;
    std::cin>>a>>b>>c>>x>>y;
    if(a+b>=2*c){
        p=p+(2*c*std::min(x,y));
    } else{
        p=p+((a+b)*std::min(x,y));
    }
    if(x!=y){
        if(x>y){
            if(a>=2*c){
                p=p+((x-y)*2*c);
            }else{
                p=p+((x-y)*a);
            }
        } else{
            if(b>=2*c){
                p=p+((y-x)*2*c);
            } else{
                p=p+((y-x)*b);
            }
        }
    }
    std::cout<<p;
    return 0;
}