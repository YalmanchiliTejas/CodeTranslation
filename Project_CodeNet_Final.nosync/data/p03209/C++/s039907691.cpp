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
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
typedef pair<ll,ll> PLL;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

VL Y(51),P(51);

ll solve(ll N,ll X){
  if(N==0) return 1;
  if(X==1) return 0;
  if(X<=Y[N-1]+1) return solve(N-1,X-1);
  if(X==Y[N-1]+2) return P[N-1]+1;
  if(X<=Y[N]-1) return P[N-1]+1+solve(N-1,X-2-Y[N-1]);
  return P[N];
}

int main(){
  ll N,X;
  cin>>N>>X;
  Y[0]=1;
  P[0]=1;
  rep(i,50) Y[i+1]=Y[i]*2+3;
  rep(i,50) P[i+1]=P[i]*2+1;
  cout<<solve(N,X)<<endl;
}