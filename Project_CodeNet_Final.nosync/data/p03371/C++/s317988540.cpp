#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;
int main(int argc, const char * argv[]) {
    int A, B, C;
    ll X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    ll sum[3] = {};
    sum[0] = X * A + Y * B;
    
    if (X > Y) {
        sum[1] = C * 2 * X;
    }else{
        sum[1] = C * 2 * Y;
    }
    
    if (X > Y) {
        sum[2] = C * 2 * Y;
        sum[2] += A * (X - Y);
    }else{
        sum[2] = C * 2 * X;
        sum[2] += B * (Y - X);
    }
    /*
    for (int i = 0; i < 3; i++) {
        cout << sum[i] << endl;
            
    }
    */
    
    ll min;
    min = sum[0];
    for (int i = 1; i < 3; i++) {
        if (min > sum[i]) {
            min = sum[i];
        }
    }
    cout << min << endl;
    return 0;
}