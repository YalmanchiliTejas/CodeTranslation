
#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int mod=1e9+7;
ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
ll inv(ll x){

    return power(x,mod-2);
}
vector<ll>g[200020];
int a[44444],b[44444];
vector<ll>v1,v2;
int main(){
    ll n,i,j,k,x,y,z,t,m;
    string s;
    cin>>s;
    if(s=="AAA"||s=="BBB")cout<<"No";
    else cout<<"Yes";
}





