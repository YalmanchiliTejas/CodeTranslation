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
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
 
int main(){
  int N;
  cin>>N;
  VI A(N);
  rep(i,N) cin>>A[i];
  sort(all(A));
  VI X(N);
  rep(i,N){
    if(i==0 or i==N-1) X[i]=1*pow(-1,i%2);
    else X[i]=2*pow(-1,i%2);
  }
  sort(all(X));
  ll ans=0;
  rep(i,N) ans+=X[i]*A[i];
  rep(i,N){
    if(i==0 or i==N-1) X[i]=-1*pow(-1,i%2);
    else X[i]=-2*pow(-1,i%2);
  }
  sort(all(X));
  ll tmp=0;
  rep(i,N) tmp+=X[i]*A[i];
  ans=max(ans,tmp);
  cout<<ans<<endl;
}