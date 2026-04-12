#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main(){
    long long A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int M = max(X, Y);
    long long res = 10000000000;
    long long p , q;
    long long r = 0;
    while(r <= 2*M){
        p = X - r/2;
        q = Y - r/2;
        if(p<0) p=0;
        if(q<0) q=0;
        res = min(res, A*p + B*q + C*r);
//        cout << p << "-" << q << "-" << r << endl;
//        cout << A*p + B*q + C*r << endl;
        r = r + 2;
    }
    cout << res << endl;
}