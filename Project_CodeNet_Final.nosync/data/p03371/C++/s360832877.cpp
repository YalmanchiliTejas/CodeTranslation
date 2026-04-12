#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    if(A+B<=2*C){
        cout << A*X+B*Y << endl;
        return 0;
    }
    ll a1=C*2*max(X,Y);
    int N=min(X,Y);
    ll a2=C*2*N+A*(X-N)+B*(Y-N);
    cout << min(a1,a2) << endl;
}