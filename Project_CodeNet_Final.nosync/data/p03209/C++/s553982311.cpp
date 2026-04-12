#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;

ll a[55],p[55];

ll f(ll N,ll x){
    if(N==0)return 1;
    else if(x==1)return 0;
    else if(x>1&&x<2+a[N-1])return (f(N-1,x-1));
    else if(x==2+a[N-1])return (p[N-1]+1);
    else if(x>2+a[N-1]&&x<3+2*a[N-1])return (p[N-1]+1+f(N-1,x-2-a[N-1]));
    else if(x==3+2*a[N-1])return (2*p[N-1]+1);
}

int main(){
    ll N,X;cin>>N>>X;
    a[0]=1;p[0]=1;
    rep(i,1,N+1){
        a[i]=2*a[i-1]+3;
        p[i]=2*p[i-1]+1;
    }
    cout<<f(N,X)<<endl;
}





