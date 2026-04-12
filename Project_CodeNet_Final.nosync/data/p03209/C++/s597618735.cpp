#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
using namespace std;
vector<ll> a(52),p(52);
ll k(int N,ll X){
    if(X==0) return 0;
    if(X==1) return (N==0)? 1:0;
    if(a[N]==X) return p[N];
    else if((a[N]+1)/2<X){
        ll res = p[N-1]+1;
        ll buf = X-a[N-1]-2;
        res+=k(N-1,buf);
        return res;
    }
    else if((a[N]/2)+1==X) return p[N-1]+1;
    else if(a[N]/2==X) return p[N-1];
    else return k(N-1, X-1);
}

int main(){
    int n;ll x;cin>>n>>x;
    a.resize(n+1),p.resize(n+1);
    a[0]=p[0]=1;//aはバーガーの総数 pはばてぃの総数
    rep(i,n){
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }
    ll res=k(n,x);
    cout<<res<<endl;
}

