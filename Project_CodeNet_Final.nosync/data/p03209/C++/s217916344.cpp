#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ll n,x;
ll ps[51];
ll ss[51];

ll rec(ll n,ll x){
    if(n==0)return 1;
    if(x==1)return 0;
    if(x<1+ss[n-1])return rec(n-1, x-1);
    if(x==1+ss[n-1])return ps[n-1];
    if(x==2+ss[n-1])return 1 + ps[n-1];
    if(x<ss[n])return 1 + ps[n-1] + rec(n-1, x-ss[n-1]-2);
    return ps[n];
}

int main(void) {
    cin >> n >> x;
    ps[0]=1;ss[0]=1;
    rep(i,51){
        if(i==0)continue;
        ps[i]=ps[i-1]*2+1;
        ss[i]=ss[i-1]*2+3;
    }
    cout << rec(n,x) << endl; 
    
    return 0;
}
