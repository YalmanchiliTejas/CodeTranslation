#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t A,B,C,X,Y,min,maisu,cost,Am,Bm,ABm;

    cin >> A >> B >> C >> X >> Y;

    if(X<Y)
        maisu = Y;
    else
    {
        maisu = X;
    }
    min = A*X+B*Y;
    for(int i=1;i<=maisu;i++){
        cost = 0;
        Am = X - i;
        Bm = Y - i;
        if(Am<0)
            Am=0;
        if(Bm<0)
            Bm=0;

        cost = Am*A + Bm*B +2*i*C;
        if(min>cost)
            min=cost;
    }
    cout << min <<endl;

    
}