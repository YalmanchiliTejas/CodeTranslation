#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int A, B, C, X, Y, p;
    p = 0;

    cin >> A >> B >> C >> X >> Y;

    while(X > 0 && Y > 0){
        if(A+B < 2 * C){
            X -= 1; Y -= 1;
            p += A + B;
        }else{
            X -= 1; Y -= 1;
            p += 2 * C;
        }
    }

    while(1){
        if(X > Y){
            if(A > C*2){
                X-=1;
                p += 2 * C;
            }else{
                X -= 1;
                p += A;
            }
        }else if(Y > X){
            if(B > C*2){
                Y-=1;
                p += 2 * C;
            }else{
                Y -= 1;
                p += B;
            } 
        }else{
            break;
        }
    }

    cout << p << endl;

    return 0; 
}