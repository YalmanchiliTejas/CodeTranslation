#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cmath>
using namespace std;
#define REP(i, limit) for(int i=0; i< limit; ++i)
#define FOR(i, j, limit) for(int i=j; i< limit; ++i)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ECHO(x) cout<<x<<endl;
#define LL long long
int INF = 2147483647;
LL LINF = 9223372036854775807;
LL MOD = 1000000007;
typedef pair<int, int>P;
typedef pair<LL, LL>PL;
typedef vector<int> vi;
typedef vector<LL> vl;

LL h[51];
LL patty[51];

LL ans(LL n, LL x){
  if(n==0&&x<=0) return 0;
  else if(n==0&&x>0) return 1;
  else if(x<=h[n-1]+1) return ans(n-1, x-1);
  else return ans(n-1, x-h[n-1]-2) +patty[n-1]+1;
}

int main(){
  int n;
  LL x;
  cin>>n>>x;

  h[0]=1;
  patty[0]=1;
  REP(i, 50){
    h[i+1]=3+2*h[i];
    patty[i+1]=1+2*patty[i];
    //cout<<i<<" "<<h[i]<<" "<<patty[i]<<endl;
  }
  cout<<ans(n, x)<<endl;

  return 0;
}
