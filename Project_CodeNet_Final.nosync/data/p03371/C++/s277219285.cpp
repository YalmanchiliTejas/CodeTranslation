#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int A,B,C,X,Y,maxim,minim,rem,ans;
    cin >> A >> B >> C >> X >> Y;
    if(A+B<C*2){
        cout << A*X + B*Y << endl;
    }else{
        maxim = max(X,Y);
        if(X==maxim){
            rem = A;
        }else{
            rem = B;
        }
        minim = min(X,Y);
        ans = min(C*2*maxim,C*2*minim+rem*(maxim-minim));
        cout << ans << endl;
    }
    return 0;
}