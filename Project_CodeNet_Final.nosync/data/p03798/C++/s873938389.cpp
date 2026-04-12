#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
const int MAX_C = 2010;
long long Com[MAX_C][MAX_C] = {0};

int main(){
  int N; string S; cin >> N >> S;
  int ans[N][4];
  if(S[0]=='o'){
    ans[0][0]=0; ans[1][0]=0; ans[N-1][0]=0;
    ans[0][1]=0; ans[1][1]=1; ans[N-1][1]=1;
    ans[0][2]=1; ans[1][2]=1; ans[N-1][2]=0;
    ans[0][3]=1; ans[1][3]=0; ans[N-1][3]=1;
  }
  else{
    ans[0][0]=0; ans[1][0]=1; ans[N-1][0]=0;
    ans[0][1]=0; ans[1][1]=0; ans[N-1][1]=1;
    ans[0][2]=1; ans[1][2]=1; ans[N-1][2]=1;
    ans[0][3]=1; ans[1][3]=0; ans[N-1][3]=0;
  }
  rep(i, 4){
    ans[N][i] = ans[0][i];
  }
  bool check[4];
  rep(i, 4)check[i]=true;
  for(int i=1; i<N; i++){
    if(S[i]=='o'){
      rep(j, 4){
        if(i==N-2 || i==N-1){
          if(ans[i][j] && ans[i-1][j]==ans[i+1][j]) check[j]=false;
          if(!(ans[i][j]) && ans[i-1][j]!=ans[i+1][j]) check[j]=false;
        }
        if(ans[i][j]) ans[i+1][j]=1-ans[i-1][j];
        else ans[i+1][j]=ans[i-1][j];                         
      }
    }
    else{
      rep(j, 4){
        if(i==N-2 || i==N-1){
          if(ans[i][j] && ans[i-1][j]!=ans[i+1][j]) check[j]=false;
          if(!(ans[i][j]) && ans[i-1][j]==ans[i+1][j]) check[j]=false;
        }
        if(ans[i][j]) ans[i+1][j]=ans[i-1][j];
        else ans[i+1][j]=1-ans[i-1][j];
      }
    }
  }
  rep(i, 4){
    if(check[i]){
      rep(j, N){
        if(ans[j][i]) cout << 'W'; else cout << 'S';
      }
      cout << endl; return 0;
    }
  }
  cout << -1 << endl;
}