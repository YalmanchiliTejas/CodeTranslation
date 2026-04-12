#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl 
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl 
#define no cout<<"no"<<endl
#define vec(a,y,x)  vector<vector<char>> a (y,vector<char>(x))
const vector<int> dx={1,0,-1,0};
const vector<int> dy={0,1,0,-1};



bool check(vector<vector<int>> &G,vector<int> permu,int n,int v){
  int a,b;
  if(v==n-1) return true;
  if(v==0) a=0;
  else a=permu.at(v-1);
  b=permu.at(v);
  if(find(all(G.at(a)),b)==G.at(a).end()) return false;
  if(!check(G,permu,n,v+1)) return false; 
  return true;
}

int main(){
  int n,m;
  int ans=0;
  cin>>n>>m;
  vector<vector<int>> G(n);
  rep(i,m){
    int a,b;
    cin>>a>>b;
    a--;b--;
    G.at(a).push_back(b);
    G.at(b).push_back(a);
  }
  vector<int> permu={};
  rep(i,n-1)
    permu.push_back(i+1);
  do{
    if(check(G,permu,n,0))
      ans++;
  }while(next_permutation(all(permu)));
  cout<<ans<<endl;  
}