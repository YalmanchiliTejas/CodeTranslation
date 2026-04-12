#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

ll a[55];

void power(){
  ll cur=1;
  rep(i,0,56){
    a[i]=cur;
    cur*=2;  }
}

ll solve(int n,ll x){
  if(x==0) return 0;
  if(n==0) return 1;
  if(x<=(a[n+1]-2)) return solve(n-1,x-1);
  return a[n]+solve(n-1,min(x-a[n+1]+1,a[n+1]-3));
}

int main(){
  int n;
  ll x;
  cin>>n>>x;
  power();
  cout<<solve(n,x)<<endl;
}