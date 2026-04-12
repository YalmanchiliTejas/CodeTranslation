#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
ll L[51];
ll f(ll n,ll x){
    if(n==0)return 1;
    else if(x==1)return 0;
    else if(x>=1&&x<=1+L[n-1])return f(n-1,x-1);
    else if(x==L[n-1]+2)return f(n-1,L[n-1])+1;
    else if(x>=(L[n-1]+3)&&x<=(2*(L[n-1]+1)))return f(n-1,L[n-1])+1+f(n-1,x-(L[n-1]+2));
    else if(x==(2*L[n-1]+3))return 2*f(n-1,L[n-1])+1;
    return 0;
}
int main(){
    ll n,x;cin>>n>>x;
    L[0]=1;
    REP(i,1,n+1){
        L[i]=L[i-1]*2+3;
    }
    cout<<f(n,x)<<endl;
}