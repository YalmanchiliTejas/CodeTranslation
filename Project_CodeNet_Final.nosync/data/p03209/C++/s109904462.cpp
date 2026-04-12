#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;
vector<ll> a(51,0);

ll ttl(ll n){
    if(n==0) a.at(n)=1;
    else a.at(n)=3+2*ttl(n-1);
    return a.at(n);
}

ll dfs(int n,ll i){
    if(!n) return 1;

    if(i==1) return 0;
    if(2<=i && i<=1+a.at(n-1)) return dfs(n-1,i-1);
    if(i==2+a.at(n-1)) return dfs(n-1,a.at(n-1))+1;
    if(3+a.at(n-1)<=i && i<=2+2*a.at(n-1)) return dfs(n-1,a.at(n-1))+1+dfs(n-1,i-2-a.at(n-1));
    else return 1+2*dfs(n-1,a.at(n-1));
}

int main(){
  ll n,x;cin>>n>>x;
  ttl(n);

  cout<<dfs(n,x);
}