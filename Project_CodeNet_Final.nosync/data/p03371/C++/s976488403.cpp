#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
  	int val=0;

    if(A > C*2){
        val= C*2*X;
        if(X<Y){
            if(B > C*2){
                val+= (Y-X)*C*2;
            }
            else{
                val+= (Y-X)*B;
            }
        }
    }
    else if(B > C*2){
        val= C*2*Y;
        if(Y<X){
            if(A > C*2){
                val+= (X-Y)*C*2;
            }
            else{
                val+= (X-Y)*A;
            }
        }
    }
    else if(A+B > C*2){
        if(X > Y){
            val = C*2*Y;
            val += A*(X-Y);
        }
        else{
            val = C*2*X;
            val += B*(Y-X);
        } 
    }
    else{
        val= A*X + B*Y;
    }
    cout << val << endl;
    return 0;
}