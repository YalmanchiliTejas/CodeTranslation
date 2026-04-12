#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    if(A+B<=C*2){
        cout << A*X+B*Y;
    }else{
        if(X==Y){
            cout << C*2*X;
        }else if(X<Y){
            if(B>=C*2){
                cout << C*2*Y;
            }else{
                cout << C*2*X+B*(Y-X);
            }
        }else{
            if(A>=C*2){
                cout << C*2*X;
            }else{
                cout << C*2*Y+A*(X-Y);
            }
        }
    }
}
