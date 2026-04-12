#include <algorithm>
#include <queue>
#include <iostream>
#include <string>
#include <set>
#include <map>
#define REP(i,n) for(ll i = 0; i < (ll)n; i++)
#define INF 1000000000000000
using namespace std;
typedef long long ll;
typedef double db;
typedef string str;
typedef pair<ll,ll> p;



ll f(ll n,ll x,vector<ll>a,vector<ll>p){
    //レベルnバーガーの下からX層に含まれるパティの数
    if(n==0 and x==0) return 0;
    if(n==0 and x>=1) return 1;
    if(x<=1){ return 0;
    }else if(x<=1+a[n-1]){ return f(n-1,x-1,a,p);
    }else if(x==2+a[n-1]){ return p[n-1] +1;
    }else if(x<=2+2*a[n-1]){ return 1+p[n-1]+f(n-1,x-2-a[n-1],a,p);
    }else{ return 2*p[n-1]+1;}
}

int main(){
    ll N,X;cin>>N>>X;
    vector<ll>a(N,1),p(N,1);
    //aはレベルiバーガーの厚さ
    //pはレベルiバーガーに含まれるパティの総数
    for(ll i = 1; i < N; i++)
    {
        a[i] = 2LL * a[i-1] + 3LL;
        p[i] = 2LL * p[i-1] + 1LL;
    }
    ll ans = f(N,X,a,p);
    cout<<ans<<endl;
}