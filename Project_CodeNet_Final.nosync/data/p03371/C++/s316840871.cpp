#include <iostream>
using namespace std;

int main(){

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if(A + B < 2 * C){
        int value = 0;
        value += X * A;
        value += Y * B;
        cout << value << endl;
        return 0;    
    }else{
        int value1 = 0, value2 = 0;        
        
        int diff;
        if(X > Y){
            diff = X - Y;
            value1 += 2 * C * Y;
            value1 += diff * A;
            value2 += 2 * C * X;
        }else{
            diff = Y - X;
            value1 += 2 * C * X;
            value1 += diff * B;
            value2 += 2 * C * Y;
        }
        if(value1 < value2) cout << value1 << endl;
        else cout << value2 << endl;
        return 0;
    }    
}