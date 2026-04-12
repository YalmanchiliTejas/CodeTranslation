#include<iostream>
int main(){
    int a,b,c,x,y,max_i,yasui;
    std::cin>>a>>b>>c>>x>>y;
    max_i=std::max(x,y);
    yasui=std::min(x,y);
    if(a+b<=c)std::cout<<x*a+y*b<<std::endl;
    else if(c*2<=a&&c*2<=b)std::cout<<c*max_i*2<<std::endl;
    else if(c*2<=a&&c*2>=b){
        if(x>y)std::cout<<c*x*2<<std::endl;
        else std::cout<<c*x*2+(y-x)*b<<std::endl;
    }
    else if(c*2>=a&&c*2<=b){
        if(x<y)std::cout<<c*y*2<<std::endl;
        else std::cout<<c*y*2+(x-y)*a<<std::endl;
    }
    else if((a+b)>=c*2&&x>=y)std::cout<<c*yasui*2+(max_i-yasui)*a<<std::endl;
    else if((a+b)>=c*2&&x<=y)std::cout<<c*yasui*2+(max_i-yasui)*b<<std::endl;
    else if(a+b<c*2)std::cout<<a*x+b*y<<std::endl;
    return 0;
}
