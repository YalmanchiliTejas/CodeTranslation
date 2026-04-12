#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(void){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int min_result{A*X+B*Y};

    for(int c{0}; c<=2*max(X, Y); c+=2){
        int result = C*c + A*(max(0, X-c/2)) + B*(max(0, Y-c/2));
        if( result < min_result){
            min_result = result;
        }
    }

    cout << min_result << endl;
}
