#include <bits/stdc++.h>
using namespace std;
#define rep(i,e) for(int i= 0; i< (int)(e); i++)
#define reps(i,s,e) for(int i = s; i < (int)(e); i++)
#define repr(i,s,e) for(int i = s; i > (int)(e); i--)
typedef long long ll;

ll num1(ll n, ll x, vector<ll> &maisu, vector<ll> &patemaisu){
    if(n==0){return 1;}
    else if(x==1){return 0;}
    else if(x==maisu[n]){return patemaisu[n];}
    else if(x<=(maisu[n]-1)/2){return num1(n-1,x-1,maisu,patemaisu);}
    else{return patemaisu[n]-num1(n,maisu[n]-x,maisu,patemaisu);}
}

int main(){
    ll n,x;
    cin >> n >> x;
    vector<ll> maisu(n+1);
    vector<ll> patemaisu(n+1);
    maisu[0] = 1;
    patemaisu[0] = 1;
    reps(i,1,n+1){
        maisu[i] = 2*maisu[i-1]+3;
        patemaisu[i] = 2*patemaisu[i-1]+1;
    }
    cout << num1(n,x,maisu,patemaisu);
}