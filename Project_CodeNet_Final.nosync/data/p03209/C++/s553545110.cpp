#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
typedef long long ll;
typedef pair<int, int> pii;
const int inf=1010001000;
const ll  INF=1001000100010001000;
const int mod=(int)1e9+7;

int n;
vector<ll>a,p;

ll solve(int n,ll x){
    if(x==0) return 0;
    if(n==0) return 1;
    if(a.at(n)/2+1<x){
        return p.at(n-1)+1+solve(n-1,x-a.at(n)/2-1);
    }
    else if(a.at(n)/2+1==x){
        return p.at(n-1)+1;
    }
    else{
        return solve(n-1,x-1);
    }
}

int main(){
    cin>>n;
    a.resize(n+1,1);
    p.resize(n+1,1);
    ll x;
    cin>>x;
    rep(i,1,n+1){
        a.at(i)=a.at(i-1)*2+3;
        p.at(i)=p.at(i-1)*2+1;
    }
    cout<<solve(n,x)<<endl;
return 0;
}