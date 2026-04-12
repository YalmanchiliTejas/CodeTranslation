#include <bits/stdc++.h>
using namespace std;


int main() {
    long long A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    if(min(A,B) >= C*2){
        cout << max(X,Y)*2*C<< endl;
    }else if(A+B >= C*2){
        if(X>=Y){
            cout << (min(A,C*2)*(X-Y)) + (C*2*Y) << endl;
        }else{
            cout << (min(B,C*2)*(Y-X)) + (C*2*X) << endl;
        }
    }else{
        cout << (A*X)+(B*Y) <<endl;
    }
}