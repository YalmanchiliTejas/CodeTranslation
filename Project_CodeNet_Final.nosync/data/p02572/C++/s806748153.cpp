#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

int main(){
    int n;
    cin >> n;
    ll pp = 1000000007;
    vector<int> A(n);
    ll sum = 0;

    rep(i,n){
        cin >> A[i];
        sum += A[i];
        sum %= pp;
    }

    ll ans = sum * sum % pp;

    rep(i,n){
        ans -= (ll)A[i] * A[i] % pp;
        if(ans < 0) ans += pp;
    } 

    ans *= (pp+1) /2;
    ans %= pp;
    cout << ans << endl;
}