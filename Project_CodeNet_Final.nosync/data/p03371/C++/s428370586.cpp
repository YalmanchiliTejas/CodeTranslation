#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    if(A+B >= C*2){
        if(X >= Y){
            if(C*2*Y + A*(X-Y) <= C*2*X) cout << C*2*Y + A*(X-Y) << endl;
            else cout << C*2*X << endl;
        }
        else{
            if(C*2*X + B*(Y-X) <= C*2*Y) cout << C*2*X + B*(Y-X) << endl;
            else cout << C*2*Y << endl;
        }
    }
    else cout << A*X + B*Y << endl;
}
