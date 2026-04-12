#include <iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

int main()
{
    int A,B,C,X,Y;
    while(cin>>A){
            int money=0;
        cin>>B>>C>>X>>Y;
        if((A+B)/2.0>C){
            if((A>2*C||B>2*C)){if(A<B){if(B>2*C){
                money=money+C*2*Y;
                X=X-Y;
                Y=0;
            }if(A>2*C&&X>0){
                money=money+C*2*X;
                Y=Y-X;
                X=0;
            }else if(X>0){money=money+X*A;X=0;}}else{if(A>2*C){
                money=money+C*2*X;
                Y=Y-X;
                X=0;
            }if(B>2*C&&Y>0){
                money=money+C*2*Y;
                X=X-Y;
                Y=0;
            }else if(Y>0){money=money+Y*B;Y=0;}}}else{
            int t=(X>Y?Y:X);
            money=money+2*t*C+(X-t)*A+(Y-t)*B;
            }
        }else{
            money=money+A*X+B*Y;
        }
        cout<<money<<endl;
    }
    return 0;
}
