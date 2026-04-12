#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <algorithm>
#include <array>
#include <complex>
#include <utility>
#include <map>
int needleX[4] = { -1,0,1,0 };
int needleY[4] = { 0,1,0,-1 };

int main(void) {
    int A,B,AB,X,Y;
    std::cin >> A >> B >> AB >> X >> Y;
    int smallxy=std::min(X,Y),bigxy=std::max(X,Y);
    
    long long ans=0;
    if(A+B>=2*AB){
        if((X>Y&&A>2*AB)||(X<Y&&B>2*AB)){
            ans+=bigxy*AB*2;
        }else{
            ans+=2*AB*smallxy;
            if(X>Y){
                ans+=(X-Y)*A;
            }
            if(X<Y){
                ans+=(Y-X)*B;
            }
        }  
    }else{
        ans+=X*A+Y*B;
    }
    
    std::cout << ans << std::endl;
    return 0;
}