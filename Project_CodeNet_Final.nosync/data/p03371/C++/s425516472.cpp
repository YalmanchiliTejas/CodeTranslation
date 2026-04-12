#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    long long int a,b,c,x,y;
    std::cin >> a >>b >> c>> x>> y;
    long long int z=abs(x-y);
    long long int ans=0;;
    if(x>y){
        ans=min(a*x+b*y,min(c*y*2+z*a,c*x*2));
    }else{
        ans=min(a*x+b*y,min(c*x*2+z*b,c*y*2));
    }
    std::cout << ans << std::endl;
}
