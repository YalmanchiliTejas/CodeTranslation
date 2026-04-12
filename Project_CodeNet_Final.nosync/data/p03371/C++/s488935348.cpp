#include<iostream>
#include<string>
using namespace std;

int main(void){
    int A,B,C,X,Y;
    int kane=0;

    cin>>A>>B>>C>>X>>Y;
    if(A+B < C*2 ){
        kane = A*X+B*Y;
        
    }else if(A > C*2 && B > C*2){
        if(X<Y){
            kane = C*Y*2;

        }else{
            kane = C*X*2;
        }
    }else if(A > C*2 && X>Y){
        kane = C*X*2;
    }else if(B > C*2 && Y>X){
        kane = C*Y*2;
    }else if(A > C*2){
        kane = C*X*2;
        kane = kane + B*(Y-X);
    }else if(B > C*2){
        kane = C*Y*2;
        kane = kane + A*(X-Y);
    }else{
        if(X<Y){
            kane = C*X*2;
            kane = kane + B*(Y-X);
        }else{
            kane = C*Y*2;
            kane = kane + A*(X-Y);
        }
    }
    cout<<kane<<"\n";
    return 0;
}