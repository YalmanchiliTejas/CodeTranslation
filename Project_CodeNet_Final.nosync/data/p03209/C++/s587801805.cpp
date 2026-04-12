#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define rep(i, s, n) for(int i = s; i < n; i++) 
#define ll long long 

ll pate[51];
ll all[51];


ll func(int n, ll x) {
    //cout << n << " " << x <<  endl;
    if(n == 0) {
        if(x <= 0) return 0;
        else return 1;
        //cout << 1 << endl;
    }

    if(x <= 1+all[n-1]) {
        return func(n-1, x-1);
        //cout << func(n-1, x-1) << endl;
        //func(n-1, x-1);
    }
    else { //if(x <= 1+2*all[n-1]+1) {
        //cout << 2*pate[n-1]+1 << endl;
        return pate[n-1]+1+func(n-1, x-all[n-1]-2);    
    }
    /*
    else if(x <= all[n-1]+1+1) {
        return pate[n-1]+1;
        //cout << pate[n-1]+1 << endl;
    }
    else if(x <= 1+2*all[n-1]+1) {
        //cout << 2*pate[n-1]+1 << endl;
        return pate[n-1]+1+func(n-1, x-all[n-1]-2);    
    }
    else {
        return 2*pate[n-1]+1;
    }
    */

}

int main() {
    int n;
    ll x;
    cin >> n >> x;

    all[0] = 1;
    pate[0] = 1;
    rep(i, 1, n+1) {
        all[i] = 2*all[i-1]+3;// + pow(2, i+1);
        pate[i] = 2*pate[i-1]+1;// + pow(2, i);
        //cout << pate[i] << endl;
    }

    int num = n;
    ll ans = func(n, x);
    cout << ans << endl;
    
    return 0;

}