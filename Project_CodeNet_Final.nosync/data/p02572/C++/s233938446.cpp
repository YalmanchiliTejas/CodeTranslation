#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
#define REP(i,m,n) for(LL i=(m);i<(n);i++)
	//i=m -> n

int main(){
  LL n,ans=0;
  cin >> n;
  VLL a(n,0),sum(n+1,0);
  sum[n] = 0;
  REP(i,0,n){
    cin >> a[i];
  }
  for(LL i=n-1; i>=0; i--){
    sum[i] = sum[i+1] + a[i];//a[i]以降の和
    sum[i] %= 1000000007;
  }
  
  REP(i,0,n-1){
    ans += a[i]*sum[i+1];
    ans %= 1000000007;
  }
  
  
  cout << ans << endl;
  
  return 0;
}
