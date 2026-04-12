#include <iostream>
using namespace std;
typedef long long ll;
ll a[51], p[51];

ll f(ll n, ll x){
    if(x<=0)return 0;
    if(x==a[n])return p[n];
    if(x>=a[n-1]+2){
        return p[n-1]+1+f(n-1, x-=a[n-1]+2);
    }else if(x==a[n-1]+1){
        return p[n-1];
    }
    return f(n-1, x-1);
}
int main() {
    ll n, x;
    cin>>n>>x;
    a[0]=1;
    p[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }
    cout<<f(n, x)<<endl;
	return 0;
}