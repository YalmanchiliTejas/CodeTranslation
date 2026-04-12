#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <math.h>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <utility>
#include <set>
#include <map>
using namespace std;
typedef long long int ll;

#define MOD 998244353


ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

bool primeNumber(ll n){
    if(n < 2) return false;
    else{
        for(ll i = 2; i * i <= n; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
}
  
  

int main() {
    ll h;
    ll w;
    cin>>h>>w;
    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }
 
    vector<bool> row(h, false);
    vector<bool> col(w, false);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (a[i][j] == '#') {
                row[i] = true;
                col[j] = true;
            }
        }
    }
 
    for (int i = 0; i < h; i++) {
        if (row[i]) {
            for (int j = 0; j < w; j++) {
                if (col[j]) {
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    return 0;
}
    
    

