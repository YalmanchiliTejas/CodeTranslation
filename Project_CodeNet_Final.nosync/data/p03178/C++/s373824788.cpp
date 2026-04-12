#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  string s;
  cin >> s;
  int d;
  cin >> d;
  int n=s.length();
  vector<LL> dp(d,0);
  int total=0;
  dp[0]=0;
  for(int i=0;i<n;i++){
    // cout << i << endl;
    vector<LL> ndp(d,0);
    for(int j=0;j<d;j++){
      for(int k=0;k<10;k++){
        ndp[(j+k)%d]=(ndp[(j+k)%d]+dp[j])%MOD;
      }
    }
    for(int j=0;j<s[i]-'0';j++){
      ndp[(total+j)%d]=(ndp[(total+j)%d]+1)%MOD;
    }
    total=(total+(int)(s[i]-'0'))%d;
    for(int j=0;j<d;j++){
      dp[j]=ndp[j];
      // cout << dp[j] << " ";
    }
    // cout << endl;
  }
  dp[total]=(dp[total]+1)%MOD;
  cout << (dp[0]-1+MOD)%MOD << endl;
  return 0;
}
