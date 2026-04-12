#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main(){
    int A,B,C,X,Y;
    std::cin >> A >> B >> C >> X >> Y;

    int price = 0;

    bool combo = (A + B) > (C * 2);
    if(combo){
        while(X != 0 && Y != 0){
            --X;
            --Y;
            price += C * 2;
        }
    }

    if(A > 0){
        if( A > C * 2){
            while(X != 0){
                --X;
                --Y; 
                price += C * 2;
            }
        }else{
            while(X != 0){
                --X;
                price += A;
            }
        }
    }

    if(B > 0){
        if( B > C * 2){
            while(Y != 0){
                --X;
                --Y; 
                price += C * 2;
            }
        }else{            
            while(Y != 0){
                --Y;
                price += B;
            }
        }
    }

    std::cout << price;
}