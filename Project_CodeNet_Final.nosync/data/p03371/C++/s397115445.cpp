#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int A, B, C, X, Y;
    int i;
    int Z;
    cin >> A >> B >> C >> X >> Y;
    int result = 0;
    if(A + B > 2 * C)
        result += min(X, Y) * 2 * C;
    else
        result += min(X, Y) * (A + B);
    if(X > Y){
        if(A > 2 * C)
            result += (X - Y) * 2 * C;
        else
            result += (X - Y) * A;
    }
    else{
        if(B > 2 * C)
            result += (Y - X) * 2 * C;
        else   
            result += (Y - X) * B;
    }

    cout << result << endl;
    return 0;
}