#include "bits/stdc++.h"
#include "math.h"
#include "string.h"
#include "algorithm"
 
using namespace std;
typedef int64_t ll;
typedef vector<int64_t> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int,int> P;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SIZE(a) int((a).size())



int main(){
  int n,m;
  cin>>n>>m;
  vvb d(n+1,vb(n+1,false));
  REP(i,m){
    int a,b;
    cin>>a>>b;
    d[a][b]=true;
    d[b][a]=true;
  }
  vector<int> v(n);
  REP(i,n){
      v[i]=i+1;
  }
  int count=0;
  do{
    int tmp=0;
    REP(i,n-1){
      if(d[v[i]][v[i+1]]){
        tmp++;
      }
      else{break;}
    }
    if(tmp==n-1){
      count++;
    }
  }while(next_permutation(v.begin()+1,v.end()));
  cout<<count<<endl;

}

