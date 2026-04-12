#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
int main(void){

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans = (2 * C * 0) + (A * max(X-0,0)) + (B * max(Y-0,0));
    
    for(int i = 1; i <= 100000; i++){
        long long buy = (2 * C * i) + (A * max(X-i,0)) + (B * max(Y-i,0));
        if(ans > buy) ans = buy;
    }
    
    cout << ans << endl;
}
