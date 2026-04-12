#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    int A,B,C,X,Y;
    cin >> A >> B >> C >> X >> Y;
    int min = A*X + B*Y; 
    for(int k=0; k<=2*max(X,Y); k+=2){
        if(A*(X-k/2) < 0) A = 0;
        if(B*(Y-k/2) < 0) B = 0;
        if(min > C*k + A*(X-k/2) + B*(Y-k/2)){
            min =  C*k + A*(X-k/2) + B*(Y-k/2);
        }
    }
    cout << min << endl;
}
