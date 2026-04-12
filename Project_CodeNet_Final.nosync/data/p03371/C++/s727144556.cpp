#include<iostream>
using namespace std;

int main(){
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    if(X < Y){
        swap(X,Y);
        swap(A,B);
    }
    long long min = 2*C*X;
    if(min > A*(X-Y)+2*C*Y) min = A*(X-Y)+2*C*Y;
    if(min > A*X+B*Y) min = A*X+B*Y;
    cout << min << endl;
    system("pause");
    return 0;
}