#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void){
    int A, B, C, X, Y;
    int ans;
    
    cin >> A >> B >> C >> X >> Y;
    
    if(A + B <= 2 * C){
        ans = A * X + B * Y;
    }
    else{
        int a, b;
        a = max(X, Y);
        b = min(X, Y);
        
        if(X >= Y){
            ans = min(2 * C * a, 2 * C * b + A * (a - b));
        }
        else{
            ans = min(2 * C * a, 2 * C * b + B * (a - b));
        }
    }
    
    cout << ans << endl;
}