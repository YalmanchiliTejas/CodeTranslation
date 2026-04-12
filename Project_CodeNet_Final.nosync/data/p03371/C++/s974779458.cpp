#include <bits/stdc++.h>
#define ll long long
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    ll i,j,k,l,m,n,w,x,y,z,p,q,tmp,sum=0;
    string str;
    ll a,b,c;
    cin>>a>>b>>c>>x>>y;
    if(x<y){
        y=y-x;
        z=x;
        x=0;
    }else{
        x=x-y;
        z=y;
        y=0;
    }
    if(a+b<c*2){
        sum=(a+b)*z;
    }else{
        sum=c*2*z;
    }
    if(a>c*2){
        sum+=x*c*2;
    }else{
        sum+=x*a;
    }
    if(b>c*2){
        sum+=y*c*2;
    }else{
        sum+=y*b;
    }
    cout<<sum<<endl;
    return 0;
}