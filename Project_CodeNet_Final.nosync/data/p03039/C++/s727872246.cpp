#include <iostream>
using namespace std;
typedef long long ll;
ll MOD = 1000000007;
ll f(ll x,ll y){
    if(y==0)return 1;
    if(y%2)return f(x,y-1)*x%MOD;
    return f(x,y/2)*f(x,y/2)%MOD;
}
ll f2(ll x){
    if(x==0)return 1;
    return f2(x-1)*x%MOD;
}
ll n,m,k;
int main(void){
    cin>>n>>m>>k;
    cout<<f2(n*m-2)*f(f2(n*m-k),MOD-2)%MOD*f(f2(k-2),MOD-2)%MOD*(m+n)%MOD*(n*m-1)%MOD*n*m%MOD*f(6,MOD-2)%MOD<<endl;
}
