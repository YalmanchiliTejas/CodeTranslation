#include <iostream>
using namespace std;
int A,B,C,X,Y;
int main(){
    cin >> A >> B >> C >> X >> Y;
    if(A + B < 2*C){
        cout << A*X + B*Y << endl;
    }else{
        if(X >= Y && A <= 2*C){
            cout << C * 2 * Y + A * (X - Y) << endl;
        }else if(Y > X && B <= 2*C){
            cout << C * 2 * X + B * (Y - X) << endl;
        }else if(X >= Y && A > 2*C){
            cout << C * 2 * X << endl;
        }else if(Y > X && B > 2*C){
            cout << C * 2 * Y << endl;
        }
    }
    return 0;
}