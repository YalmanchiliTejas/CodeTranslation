#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  int H,W;
  cin>>H>>W;
  string A[H];
  rep(i,H) cin>>A[i];
  VI HH(H),WW(W);
  rep(i,H){
    int cnt=0;
    rep(j,W) if(A[i][j]=='.') cnt++;
    if(cnt==W) HH[i]++;
  }
  rep(i,W){
    int cnt=0;
    rep(j,H) if(A[j][i]=='.') cnt++;
    if(cnt==H) WW[i]++;
  }
  rep(i,H){
    rep(j,W) if(HH[i]==0&&WW[j]==0) cout<<A[i][j];
    if(HH[i]==0) cout<<endl;
  }
}

