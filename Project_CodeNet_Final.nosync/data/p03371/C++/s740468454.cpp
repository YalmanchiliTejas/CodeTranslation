#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int main(){
    long long A,B,C,X,Y;
    
    cin >> A >> B >> C >> X >> Y;
    if(A+B <= 2*C){
        cout << A*X + B*Y << endl;
    }else{
        int m = min(X,Y);
        //if(m % 2 == 1){
        //    m--;
        //}
        cout << min(m*C*2 + (X-m)*A + (Y-m)*B,2*C*max(X,Y)) << endl;
    }
}
