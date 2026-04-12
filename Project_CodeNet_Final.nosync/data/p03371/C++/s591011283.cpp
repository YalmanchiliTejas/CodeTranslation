#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if(A+B <= C*2){
        cout << A*X + B*Y << endl;
    }else{
        int res1, res2;
        if(X > Y){
            res1 = C*min(X, Y)*2 + (X-Y)*A;
        }else{
            res1 = C*min(X, Y)*2 + (Y-X)*B;
        }
        res2 = C*max(X, Y)*2;
        cout << min(res1, res2) << endl;
    }
    return 0;
}