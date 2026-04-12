#include <iostream>

using namespace std;
int main(){
    int A,B,C,X,Y;
    int price = 0;
    cin >> A >> B >> C >> X >> Y;
    while(X > 0 || Y > 0){
        if(A+B > C*2 && X > 0 && Y > 0){
            price += C*2;
            X--;
            Y--;
            continue;
        }
        if(A > C*2 && X >0){
            price += C*2;
            X--;
            Y--;
            continue;
        }
        if(X > 0){
            price += A;
            X--;
            continue;
        }
        if(B > C*2 && Y > 0){
            price += C*2;
            X--;
            Y--;
            continue;
        }
        if(Y > 0){
            price += B;
            Y--;
            continue;
        }
    }
    cout << price << endl;
}
