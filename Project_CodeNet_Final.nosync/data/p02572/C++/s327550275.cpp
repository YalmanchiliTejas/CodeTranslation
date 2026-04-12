#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    unsigned long long A[N];
    unsigned long long s[N+1];
    unsigned long long sum = 0;
    s[0] = 0;
    for(int i=0;i<N;i++){
        cin >> A[i];
        s[i+1] = s[i]+A[i];
    }
    for(int i=0;i<N-1;i++){
        sum = sum+A[i]*((s[N]-s[i+1])%1000000007);
        sum = sum%1000000007;
    }
    printf("%llu\n",sum);
    return 0;
}