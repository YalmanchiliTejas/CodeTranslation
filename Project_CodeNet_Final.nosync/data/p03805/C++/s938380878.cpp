#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
using mat=vector<vec>;
#define For(i,a,b) for(ll i=a;i<b;i++)
#define bFor(i,a,b) for(ll i=a;i>=b;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N-1,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define mod 1000000007
#define endl "\n"
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}while(0)
using datas=pair<ll,ll>;
using tdata=pair<ll,datas>;

ll N;
mat v;
ll search(ll now,vec& a){
  ll K,ans=1;
  K=v[now].size();
  vec b(N);
  a[now]++;
  rep(i,N){
    b[i]=a[i];
    if(b[i]==0)ans=0;
  }
  a[now]--;
  if(ans)return ans;
  rep(i,K){
    if(b[v[now][i]]==0){
      ans+=search(v[now][i],b);
    }
  }
  return ans;
}
int main(){
  ll K,s,g;
  cin>>N>>K;
  v.resize(N);
  vec a(N,0);
  rep(i,K){
    cin>>s>>g;
    s--;g--;
    v[s].push_back(g);
    v[g].push_back(s);
  }
 
  cout<<search(0,a)<<endl;
  return 0;
}