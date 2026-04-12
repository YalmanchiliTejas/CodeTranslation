#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

vector<int> v[8];
int at[8];

int dfs(int a,int n){
  int c=0;
  rep(i,n){
    if(at[i]==0){
      c++;
    }
  }
  if(c==0) return 1;
  int ans=0;
  for(int u:v[a]){
    if(at[u]==1) continue;
    at[u]=1;
    ans+=dfs(u,n);
    at[u]=0;
  }
  
  return ans;
}
  


int main(){
  int n,m;cin>>n>>m;
  int a,b;
  rep(i,m){
    cin>>a>>b;
    a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  rep(i,n) at[i]=0;
  at[0]=1;
  cout<<dfs(0,n)<<endl;
}