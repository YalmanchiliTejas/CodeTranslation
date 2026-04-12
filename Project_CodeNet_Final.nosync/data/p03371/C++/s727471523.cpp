#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int flag = 0;

    if((A/2 + B/2) < C)
        flag = 1; 

    int dif, c_num;
    if(flag == 0){
        if(X > Y){
            if(2*C > A)
                dif = A*(X - Y);
            else
                dif = 2*C*(X - Y);
            c_num = Y;
        }else {
            if(2*C > B)
                dif = B*(Y - X);
            else
                dif = 2*C*(Y - X);
            c_num = X;            
        }
        cout << 2*C*c_num + dif << endl;
    }else {
        cout <<  A*X + B*Y << endl;
    }



    return 0;
}