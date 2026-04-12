#include <cstdio>
#include <string>
#include <cmath>
#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// C - Half and Half
int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int allAB = A*X + B*Y;
    int A_AB_B = C*2*X + B*(Y-X);
    int B_AB_A = C*2*Y + A*(X-Y);
    if(X>Y){
        A_AB_B = C*2*X;
        B_AB_A = C*2*Y + A*(X-Y);
    }else if(Y>X){
        B_AB_A = C*2*Y;
        A_AB_B = C*2*X + B*(Y-X);
    }
    int ans = min(allAB, min(A_AB_B, B_AB_A));

    cout << ans << endl;
    return 0;
}


