#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll com(ll n, ll r){
    if(r<0 || r>n) return 0;
    if(r==1) return n;
    else if(r==2) return n*(n-1)/2;
    else return n*(n-1)*(n-2)/6;
}
ll pow(ll n, ll k){
    ll res=1;
    rep(i,k) res*=n;
    return res;
}

ll n,k; string s;
ll rec(ll i, ll k, bool smaller){
    if(i==n){
        if(k==0) return 1;
        else return 0;
    }
    if(k==0) return 1;
    if(smaller) return com(n-i,k)*pow(9,k);
    else{
        if(s[i]=='0') return rec(i+1,k,false);
        else{
            ll zero=rec(i+1,k,true);
            ll aida=rec(i+1,k-1,true)*(s[i]-'1');
            ll icchi=rec(i+1,k-1,false);
            return zero+aida+icchi;
        }
    }
}

int main(){
    cin>>s>>k;
    n=s.size();
    cout<<rec(0,k,false)<<endl;
    return 0;
}