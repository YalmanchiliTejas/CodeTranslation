#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
const long nPrime = 1000000007;

int main(){
    int n;
    scanf("%d", &n);
    vector <long> vi(n);
    long iSum = 0;
    for(int i = 0; i < n; i++){
        scanf("%ld", &vi[i]);
        iSum += vi[i];
        iSum %= nPrime;
    }
    long nAns = iSum * iSum;
    nAns %= nPrime;
    for(int i = 0; i < n; i++){
        long iSquare = vi[i] * vi[i];
        iSquare %= nPrime;
        nAns -= iSquare;
        nAns %= nPrime;
    }
    
    if(nAns < 0){
        nAns += nPrime;
    }
    if(nAns % 2 != 0){
        nAns += nPrime;
    }
    printf("%ld", nAns / 2);
    return 0;
}
