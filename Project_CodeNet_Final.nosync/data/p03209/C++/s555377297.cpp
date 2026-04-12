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
  LL ans=0;
  while(n>=0 && x>0){
    if(n==0&&x==1) {
      ++ans;
      break;
    }
    else if(x<h[n-1]+1){
      --x;
      --n;
    }
    else if(x==h[n-1]+1){
      ans += patty[n-1];
      break;
    }
    else if(x==h[n-1]+2){
      ans += patty[n-1]+1;
      break;
    }
    else{
      ans += patty[n-1]+1;
      x -= h[n-1]+2;
      --n;
    }
    //cout<<n<<" "<<x<<" "<<ans<<endl;
  }
  //cout<<n<<" "<<x<<" "<<ans<<endl;
  cout<<ans<<endl;

  return 0;
}
