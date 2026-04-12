#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll INF=mod*mod;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(x) (x).begin(),(x).end()
ll min(ll a,ll b){
  if(a>b){
    return b;
    }
      else{
        return a;
      }
  }
  
  ll max(ll a,ll b){
    if(a>b){
      return a;
    }
    else{
      return b;
    }
  }

ll power(ll a,ll b){
 ll ans=1;
 for(ll i=1;i<=b;i++){
ans*=a;
  }
  return ans;
}

 ll gcd(ll m,ll n){
 	if(n==0){
       return m;
     }
   return gcd(n,m%n);
 }
ll lcm(ll a,ll b){
  ll g=gcd(a,b);
  return a/gcd(a,b)*b;
		

}

ll N,M;
const ll limit=28;

ll a[limit];
ll b[limit];

 bool G[limit][limit];



ll dfs(ll v,bool visited[limit]){//vは現在位置、visitedはvまでどこを通ってきたか記録？
 bool ALL=true;
rep(i,N){ 
if(visited[i]==false){
ALL=false;
}
}
if(ALL){
  return 1;//全ての点を通っていたら１を足す
}

ll ret=0;

rep(i,N){
if(G[v][i]==true&&visited[i]==false){
  
  visited[i]=true;
  ret+=dfs(i,visited);//vから次のステップへのdfs生成？？？
  visited[i]=false;//visited[i]=trueを積んだdfsを生成した後falseに戻すイメージ
}
}
return ret;//dfs生成？？？
}


    
int main(){
  cin>>N>>M;

  
  rep(i,M){
    cin>>a[i]>>b[i];
    G[a[i]-1][b[i]-1]=G[b[i]-1][a[i]-1]=true;
  }
  bool visited[limit];
rep(i,N){
  visited[i]=false;
  
}

  visited[0]=true;
  
  cout<<dfs(0,visited)<<endl;
}
