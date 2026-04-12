#include<iostream>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    long long int ans = 0;
    if(A+B <= C*2){
        ans = A*X+B*Y;
    }
    else{
        int m = min(X, Y);
        ans += C*2*m;
        X -= m;
        Y -= m;

        ans += min(A,C*2)*X;
        ans += min(B,C*2)*Y;
    }
    cout << ans << endl;
    return 0;
}
