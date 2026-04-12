#include<bits/stdc++.h>
using namespace std;

int getDight(long long n){
    return (int)(log10(n) + 1);
}

void calculate(){
    long long A,B,AB,AN,BN;
    cin >> A >> B >> AB >> AN >> BN;
    long long SAB = A * AN + B * BN;
    long long SoAB = AB * max(AN,BN) * 2;
    long long SABaO = AB * min(AN,BN) * 2 + abs(AN - BN) * (AN > BN ? A : B);
    cout << min({SAB,SoAB,SABaO}) << '\n';
}

int main(int, char**) {
    calculate();
    return 0;
}
