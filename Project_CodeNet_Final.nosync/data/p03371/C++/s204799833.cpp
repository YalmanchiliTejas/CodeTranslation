#include <iostream>
#include <algorithm>
using namespace std;

int main(){

    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    long int a,b,ab;

    a = A*X + B*Y;
    if(X > Y){
        b = 2*C*Y + A*(X-Y);
        ab = 2*C*X;
    }else{
        b = 2*C*X + B*(Y-X);
        ab = 2*C*Y;
    }

    cout << min(a,min(b,ab)) << endl;


    return 0;
}