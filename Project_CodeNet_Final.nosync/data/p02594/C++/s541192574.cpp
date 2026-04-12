// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
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
    int x;
    cin >> x;
    string ans = "Yes";
    if(x < 30){
        ans = "No";
    }
    cout << ans << endl;
}
