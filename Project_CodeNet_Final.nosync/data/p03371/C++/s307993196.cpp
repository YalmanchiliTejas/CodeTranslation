#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    if(C*2<=A && C*2<=B){
        cout << max(X,Y)*C*2 << endl;
    }else if(C*2<=A+B && X<=Y){
        if(C*2<B){
            cout << max(X,Y)*C*2 << endl;
        }else{
            cout << X*C*2 + (Y-X)*B << endl;
        }
    }else if (C*2<=A+B && Y<=X){
        if(C*2<A){
            cout << max(X,Y)*C*2 << endl;
        }else{
            cout << Y*C*2 + (X-Y)*A << endl;
        }
    }else{
        cout << A*X + B*Y << endl;
    }
}