#include <iostream>
using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = X*A + Y*B;
    for(int i = 1; i <= 100000; i++)
        ans = min(ans, 2*C*i + max(X-i, 0)*A + max(Y-i, 0)*B);
    
    cout << ans << endl;

    return 0;
}