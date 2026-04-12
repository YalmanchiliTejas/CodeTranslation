#include <bits/stdc++.h>
using namespace std;


void solve(long long X, long long Y, long long Z){
    cout << (X - Z) / (Y + Z) << endl;
}

int main(){
    long long X;
    scanf("%lld",&X);
    long long Y;
    scanf("%lld",&Y);
    long long Z;
    scanf("%lld",&Z);
    solve(X, Y, Z);
    return 0;
}
