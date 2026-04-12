#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
typedef long double ld;
const ll MOD=1000000007;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
long long gcd(long long a,long long b){
    ll gcdmax=max(a,b);
    ll gcdmin=min(a,b);
    while(true){
        if(gcdmax%gcdmin==0)break;
        else gcdmax%=gcdmin;
        swap(gcdmin,gcdmax);
    }
    return gcdmin;
}
ll powerup(ll N,ll P,ll M){
    if(P==0)return 1;
    else if(P%2==0){
        ll t=powerup(N,P/2,M);
        return t*t%M;
    }
    else return N*powerup(N,P-1,M)%M;
}
vector<ll> find_divisor(ll N){
  ll k=1;
  while(k*k<=N){
    k++;
  }
  vector<ll> A(1);
  rep(i,k){
    if(i==1)A.at(0)=1;
    else if(i>=2){
      if(N%i==0)A.push_back(i);
    }
  }
  ll t=0;
  t=A.size();
  rep(i,t){
    if(A.at(t-i-1)*A.at(t-i-1)!=N)A.push_back(N/A.at(t-1-i));
  }
  return A;
}
const ll nmax=8;
bool graph[nmax][nmax];
ll dfs(ll v,ll N,bool visited[nmax]){
   bool all_visited=true;
   for(ll i=0;i<N;++i){
     if(visited[i]==false)all_visited=false;
   }
   if(all_visited){
     return 1;
    }
ll ret=0;
for(ll i=0;i<N;++i){
  if(graph[v][i]==false) continue;
  if(visited[i]) continue;
  visited[i]=true;
  ret+=dfs(i,N,visited);
  visited[i]=false;
  }
  return ret;
} 
int main()
{
  ll N,M,a,b;
  cin>>N>>M;
  rep(i,M){
    cin>>a>>b;
    graph[a-1][b-1]=true;
    graph[b-1][a-1]=true;
  }
  bool visited[8];
  for(ll i=0;i<=N;i++){
    visited[i]=false;
  }
  visited[0]=true;
  ll Z=0;
  cout<<dfs(Z,N,visited)<<endl;
}