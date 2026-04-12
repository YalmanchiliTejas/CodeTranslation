#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
int main()
{
    long A,B,C,X,Y;
    std::cin >> A >> B >> C >> X >> Y;
    if(A+B<=C*2){
        std::cout << A*X+B*Y << std::endl;
    }else{
        if(X<Y){
            long temp;
            temp=X;
            X=Y;
            Y=temp;
            temp=A;
            A=B;
            B=temp;
        }
        long value=2*Y*C;
        X=X-Y;
        if(A>=2*C){
            value+=2*X*C;
        }else{
            value+=A*X;
        }
        std::cout << value << std::endl;
    }
    return 0;
}