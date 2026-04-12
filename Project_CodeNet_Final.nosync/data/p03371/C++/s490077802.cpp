#include "bits/stdc++.h"
using namespace std;

int main() {
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;

    long long  mini=2*C*max(X,Y);
    for(long long i=1;i<=max(X,Y);i++){

        if(max(X,Y)-i>=X) mini=min(mini,B*i+2*C*(max(X,Y)-i));
        else if(max(X,Y)-i>=Y) mini=min(mini,A*i+2*C*(max(X,Y)-i));
        
        if(i>X) mini=min(mini,A*X+B*i+2*C*(max(X,Y)-i));
        else if(i>Y) mini=min(mini,B*Y+A*i+2*C*(max(X,Y)-i));
        else mini=min(mini,(A+B)*i+2*C*(max(X,Y)-i));
    }
    cout << mini << endl;
}