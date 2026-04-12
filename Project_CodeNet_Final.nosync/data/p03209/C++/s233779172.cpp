#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

vector<ll> a(55),p(55);

ll f(ll n,ll x){
    if(n<=0) return (x<=0)?0:1;
    if(x<=a[n-1]+1) return f(n-1,x-1);
    if(x==2+a[n-1]) return p[n-1]+1;
    if(x<=2+2*a[n-1]) return p[n-1]+1+f(n-1,x-2-a[n-1]);
    if(x==3+2*a[n-1]) return 2*p[n-1]+1;

}

int main(){
    int n;
    ll x;
    cin>>n>>x;
    a[0]=1;
    p[0]=1;
    for(int i=0;i<n;i++){
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }
    cout<<f(n,x)<<endl;
}