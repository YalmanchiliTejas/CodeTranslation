#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
string s;
int n,k;

//k<=3より
ll comb(ll n, ll r){
    if(r==1) return n;
    else if(r==2) return n*(n-1)/2;
    else return n*(n-1)*(n-2)/6;
}

ll pow(ll n, ll k){
    ll res = 1;
    rep(i,k) res*= n;
    return res;
}

ll solve(ll i, ll k, ll smaller){
    if(i==n){
        if(k==0) return 1;
        else return 0;
    }
    if(k==0) return 1;

    if(smaller) return comb(n-i,k) * pow(9,k);
    else{
        if(s[i]=='0') return solve(i+1,k,false);
        else{
            ll zero = solve(i+1,k,true);
            ll aida = solve(i+1,k-1,true)*(s[i]-'1');
            ll same = solve(i+1,k-1,false);
            return zero + aida + same;
        }
    }
}

int main(){
    cin>>s>>k;
    n = s.size();
    cout << solve(0,k,false) << endl;
}