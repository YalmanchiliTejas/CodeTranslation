#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve(long long X, long long Y, long long Z){
    X-= Z;
    cout << X / (Y+Z) << endl;
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
