#include <iostream>
#include<string>
#include<math.h>
using namespace std;


int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int money=0;
    if(A+B>2*C){
        
        if(X>Y){
            money+=C*Y*2;
            X-=Y;
            Y=0;
            if(A>2*C){
                money+=X*2*C;
            }else{
                money+=X*A;
            }
        }else{
            money+=C*X*2;
            Y-=X;
            X=0;
            if(B>2*C){
                money+=Y*2*C;
            }else{
                money+=Y*B;
            }
        }
    }else{
        money+=A*X + B*Y;
    }
    cout << money;
	return 0;
}