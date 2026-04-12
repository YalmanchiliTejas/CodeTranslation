#include <iostream>  // cin,cout
#include <stdio.h>   // printf,scanf (standard input/output)
#include <cmath>     // abs(x),pow(x,2)
#include <string>
#include <string.h>  // strlen, strcmp
#include <algorithm> // min,max, sort(v.begin(),v.end())
#include <vector>
#include <time.h>
using namespace std;

long long result = 0;
long long H[50], P[50];

int Func(int N, long long X){
    if (N==0) {
        if (X==0) return 0;
        else if (X==1) {
            result += 1;
            return 0;
        }
    }
    else {
        if (X==1) return 0;
        if (2<=X and X<=H[N-1]+1) Func(N-1, X-1);
        if (X==H[N-1]+2) {
            result += P[N-1] + 1;
            return 0;
        }
        if (H[N-1]+2<X and X<=2*H[N-1]+2) {
            result += P[N-1] + 1;
            Func(N-1, X-H[N-1]-2);
        }
        if (X==2*H[N-1]+3) {
            result += 2*P[N-1] + 1;
            return 0;
        }
    }
}

int main(){
    int N;
    long long X;
    
    cin >> N;
    cin >> X;
    
    H[0] = 1;
    P[0] = 1;
    for (int i=1;i<N;i++) {
        H[i] = 2*H[i-1]+3;
        P[i] = 2*P[i-1]+1;
    }
    
    Func(N, X);
    cout << result << endl;
    
    return 0;
}