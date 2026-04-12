#include <iostream>
#include <string>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main(){
        int A, B, C, X, Y;
        cin >> A >> B >> C >> X >> Y;
        int cost = 0;
        if(C * 2 <= A + B){
            while(X >= 1 && Y >= 1){
                cost += C * 2;
                X--;
                Y--;
            }
        }

                if(X > 1 && A > C * 2){
                  cost += X * (C * 2);
                  Y -= X;
                }else{
                    cost += X * A;
                }

                if(Y > 1 && B > C * 2){
                  cost += Y * (C * 2);
                }else{
                    cost += Y * B;
                }

        cout << cost << endl;
  return 0;
}
