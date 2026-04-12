#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include<math.h>
using namespace std;

typedef long long int ll;
ll  a[51];
ll  p[51];


ll f(ll N,ll X){
    if (N!=0){
        if (X <= 0){
            return 0;
        }
        else if (X == 1){
            return 0;
        }
        else if (X > 1 && X <=a[N-1]+1){
            return f(N-1,X-1);
        }
        else if(X == a[N-1]+2){
            return p[N-1]+1;
        }
        else if(X >= a[N-1]+3 && X <= 2*a[N-1]+2){
            return p[N-1]+ f(N-1,X-a[N-1]-2)+1;
        }
        else {
            return 2*p[N-1]+1;
        }
    }
    else{
        if (X == 0){
            return 0;
        }
        else {
            return 1;
        }
    }
}


int main() {
    ll  N,X; cin >> N >> X;
    a[0] = 1;
    for (ll i=1;i<= 50;i++){
        a[i] = 2*a[i-1]+3;
    }
    p[0] = 1;
    for (ll i=1; i<=50;i++){
        p[i] = 2*p[i-1]+1;
        
    }
    cout << f(N,X) << endl;
    
    return 0;
}
