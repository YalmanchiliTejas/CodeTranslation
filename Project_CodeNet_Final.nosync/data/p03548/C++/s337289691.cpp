#include <bits/stdc++.h>
using namespace std;

int main() {
    int X, Y, Z;
    
    cin >> X >> Y >> Z;
    
    int N = 0;
    
    X -= Z;
    while(X >= Y+Z){
        X -= Y+Z;
        N++;
    }
    
    cout << N << endl;
    
    return 0;
}