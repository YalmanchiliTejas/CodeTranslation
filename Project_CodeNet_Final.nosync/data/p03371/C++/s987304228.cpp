#include <iostream>
using namespace std;


int main(){

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;


    int money = 0;

    if( A + B > 2*C ){
        money += 2*C * min( X, Y );
        if( X > Y ){
            if( A > 2*C ) money += 2*C * (X - Y);
            else money += A * (X - Y);
        }else{
            if( B > 2*C ) money += 2*C * (Y - X);
            else money += B * (Y - X);
        }
    }else{
        money += A*X + B*Y;
    }

    cout << money << endl;

    return 0;

}