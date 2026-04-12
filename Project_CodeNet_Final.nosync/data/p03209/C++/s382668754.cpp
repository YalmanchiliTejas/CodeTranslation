#include<iostream>
#include <math.h>
using namespace std;

unsigned long long sub(int N, unsigned long long X) {
    if (N>0 && X<=1) {
        return 0;
    }
    if (N==0 && X>0) { 
        return 1;
    }
    if (N==0 && X==0) { 
        return 0;
    }
    unsigned long long len = pow(2, N+2) - 3;

    unsigned long long len_prev = pow(2, N+1) - 3;
    if (X==len) {
        return 2*sub(N-1, len_prev)+1;
    } else if (X<=len_prev+1) {
        return sub(N-1, X-1);
    } else if (X>len_prev+2) {
        return 1 + sub(N-1, len_prev) + sub(N-1, X-len_prev-2);
    } else {
        return 1 + sub(N-1, len_prev);
    }
}

int main() {
    int N;
    unsigned long long X;
    cin >> N >> X;
    unsigned long long ans = sub(N, X);
    cout << ans << endl;
    return 0;
}