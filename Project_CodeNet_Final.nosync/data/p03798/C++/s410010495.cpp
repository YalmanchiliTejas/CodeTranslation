#include<bits/stdc++.h>
using namespace std;
typedef int64_t ll;
#define REP(i,m,n) for (int i=m;i<n;i++)
#define FOR(i,m,n,a) for(int i=m;i<n;i+=a)
const ll MOD=1e9+7;
 
int n;
char p[100002];
bool ans[100002];
 
bool solve(){
  REP(i,2,n+2){
    if(p[i-1]=='o'){
      ans[i]=(ans[i-1])?ans[i-2]:(!ans[i-2]);
    }
    else{
      ans[i]=(ans[i-1])?(!ans[i-2]):ans[i-2];
    }
  }
 
  if(ans[0]==ans[n]&&ans[1]==ans[n+1]){
    REP(i,0,n){
      cout << (ans[i]?'S':'W');
    }
    cout << endl;
    return true;
  }
  return false;
}
 
int main(){
  cin >> n >> p;
  p[n]=p[0];p[n+1]=p[1];
 
  bool PAT[4][2]={{true,true},{true,false},{false,true},{false,false}};
  REP(i,0,4){
    ans[0]=PAT[i][0];
    ans[1]=PAT[i][1];
 
    if(solve()){
      return 0;
    }
  }
  cout << "-1" << endl;
  return 0;
}