#include<iostream>
#include<vector>
using ll = long long;

int main(){
    int A, B, C, X, Y;
    std::cin >> A >> B >> C >> X >> Y;
    
    ll min_cost = 0;
    int A1useC = 1, B1useC = 1, C1useC = 1;
    ll A1piece, B1piece, AB1piece;
    if(A > 2 * C){
        A1piece = 2 * C;
    }else{
        A1piece = A;
        A1useC = 0;
    }
    if(B > 2 * C){
        B1piece = 2 * C;
    }else{
        B1piece = B;
        B1useC = 0;
    }
    if(A + B > 2 * C){
        AB1piece = 2 * C;
    }else{
        AB1piece = A + B;
        C1useC = 0;
    }


    int xymin = std::min(X, Y);
    min_cost += xymin * AB1piece;
    if(X > Y){
        min_cost += (X - xymin) * A1piece;
    }else if(X < Y){
        min_cost += (Y - xymin) * B1piece;
    }

    std::cout << min_cost << std::endl;
    return 0;
}