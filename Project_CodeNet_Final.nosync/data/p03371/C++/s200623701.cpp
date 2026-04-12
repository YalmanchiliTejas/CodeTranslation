#include <bits/stdc++.h>
using namespace std;


int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int pay[3]={0};
    
    pay[0] = A*X+B*Y;
    
    pay[1] = C*2 * max(X,Y);
    
    if(X>Y){
        pay[2] = A*(X-Y)+C*2*Y;
    }
    else {
        pay[2] = B*(Y-X)+C*2*X;
    }
    
    cout << min(pay[0],min(pay[1],pay[2])) << endl;
}
