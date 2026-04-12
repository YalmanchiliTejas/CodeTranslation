#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long A, B, C, X, Y;
    cin>>A>>B>>C>>X>>Y;
    if(A+B<=2*C){
        cout<<A*X+B*Y<<endl;
    }
    else {
        long ans = 0;
        ans += 2*C*min(X, Y);
        if(X>Y){
            if((X-Y)*(2*C) < A*(X-Y)) ans += (X-Y)*(2*C);
            else ans += A*(X-Y);
        }
        else{
            if((Y-X)*(2*C) < B*(Y-X)) ans += (Y-X)*(2*C);
            else ans += B*(Y-X);
        }
        cout<<ans<<endl;
    }
}
