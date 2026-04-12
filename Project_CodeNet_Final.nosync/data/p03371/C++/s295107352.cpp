#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int minv = 2000000000;
    for(int i = 0; i <= 100000; i++) {
        int v = 2 * C * i + max(X - i, 0) * A + max(Y - i, 0) * B;
        minv = min(v, minv);
    }
    
    cout << minv << endl;

    return 0;
}
