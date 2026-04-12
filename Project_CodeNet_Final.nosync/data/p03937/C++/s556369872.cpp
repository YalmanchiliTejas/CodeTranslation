#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
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
  vector<string> A(H);
  rep(i,H) cin>>A[i];
  int sum=0;
  rep(i,H) rep(j,W) if(A[i][j]=='#') sum++;
  if(sum==H+W-1) cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
}