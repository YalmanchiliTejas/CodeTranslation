//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
//using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

    vector<ll>a,p;
ll f(ll n,ll x){
        if(n==0)return 1;
        if(x==1)return 0;

    else if(x<=1+a[n-1])return f(n-1,x-1);
    else if(x==2+a[n-1])return p[n-1]+1;
    else if(x<=2+2*a[n-1])return p[n-1]+1+f(n-1,x-2-a[n-1]);
    else if(x==3+2*a[n-1])return 2*p[n-1]+1;
}
int main(){
    ll N,X; 
    cin>>N>>X;
    a.resize(N+1);
    p.resize(N+1);
    a[0]=1;
    p[0]=1;
    for(int i=1;i<=N;i++){
        a[i]=a[i-1]*2+3;
        p[i]=p[i-1]*2+1;
    }
    cout<<f(N,X)<<endl;
}









