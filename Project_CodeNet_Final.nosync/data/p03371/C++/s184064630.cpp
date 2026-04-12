#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long ans = 1000000000;
    for(int i=0; i<=X; i++){
        int k = (X-i)*2;
        int j = max(Y - k/2, 0);
        long t = A*i + B*j + C*k;
        if(t < ans) ans = t;
    }
    for(int j=0; j<=Y; j++){
        int k = (Y-j)*2;
        int i = max(X - k/2, 0);
        long t = A*i + B*j + C*k;
        if(t < ans) ans = t;
    }

    cout << ans;

    return 0;
}