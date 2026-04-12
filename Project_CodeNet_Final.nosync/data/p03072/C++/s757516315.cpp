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
  
  

int main(){
    ll n;
    cin>>n;
    vector <ll> h(n);
    for (ll i = 0; i < n; i++){
        cin>>h[i];
    }
    ll ans = 0;
    for (ll i = 0; i<n; i++){
        bool flag =true;
        for (ll j = 0; j<i; j++){
            if(h[j] > h[i])flag = false;
        }
        if(flag)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
