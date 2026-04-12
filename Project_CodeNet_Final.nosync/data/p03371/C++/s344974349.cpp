#include <bits/stdc++.h>
using namespace std;


int main()
{
    stringstream ss;
    // 入力
    int A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    int price=0;
    if(2*C>A+B) {
        price=X*A+Y*B;
    }
    else if (X>Y)
    {
        if(2*C<A){
            price=2*C*X;

        }
        else{
            price=2*C*Y+(X-Y)*A;
        /* code */
        }
    }
    else if(Y>=X)
    {
        if(2*C<B){
            price=2*C*Y;
        } else{
            price=2*C*X+(Y-X)*B;
        }

    }
    cout<<price<<endl;
    return 0;
}