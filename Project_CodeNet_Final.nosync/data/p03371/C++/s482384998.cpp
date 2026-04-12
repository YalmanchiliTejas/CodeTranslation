#include<bits/stdc++.h>
using namespace std;
int main(){
    int A,B,C,X,Y; cin >> A >> B >> C >> X >> Y;
    int sum = 0;
    if(A+B > 2*C){
        int p = min(X,Y);
        sum += 2*C * p;
        X-=p; Y-=p;
        if(X != 0){
            if(X*A < 2*C*X) sum += X*A;
            else sum += 2*C*X;
        }else{
            if(Y*B < 2*C*Y) sum += Y*B;
            else sum += 2*C*Y;
        }
    }else{
        sum += A*X+B*Y;
    }
    cout << sum << endl;
}