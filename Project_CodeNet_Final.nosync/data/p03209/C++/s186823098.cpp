#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <iomanip>
#define ll long long
using namespace std;

long long int Calc(ll n, ll x){
    ll co[n+1]; co[0] = 1;
    ll pa[n+1]; pa[0] = 1;
    for(ll i = 1; i <= n; i++){
        co[i] = co[i-1]*2+3;
        pa[i] = pa[i-1]*2+1;
    }
    if(n == 0) return 1;
    else if(x == 1) return  0;
    else if(x > 1 && x < co[n-1]+2) return  Calc(n-1, x-1);
    else if(x == co[n-1]+2) return  pa[n-1]+1;
    else if(x > co[n-1]+2 && x < 2*co[n-1]+3) return  pa[n-1]+1+Calc(n-1, x-co[n-1]-2);
    else return pa[n];
}

int main(void){
    ll n, x;
    cin >> n >> x;
    cout << Calc(n, x) << endl;
    return 0;
}
