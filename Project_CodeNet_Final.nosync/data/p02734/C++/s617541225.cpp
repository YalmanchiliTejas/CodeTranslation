#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define MOD 998244353
#define chmin(a,b) (a>(b)?a=(b),1:0)
#define rep(i,n) for(int i=0;i<(n);i++)
#define df 0
void print(vector<li> v){
  for(int x:v)printf("%d ",x); printf("\n");
} 
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }


int main(){
  int n,s; cin >>n >>s;
  vector<int> a(n); rep(i,n) cin >> a[i];
  li cnt =0;
  rep(i,n) if(a[i]==s) (cnt+=(i+1)*(n-i))%=MOD;
  if(df)print(cnt);
  vector<li> dp(s+1,0);
  dp[0]=1; dp[s]=cnt;
  rep(i,n){
    if(df)printf("i:%d\n",i);
    if(a[i]>=s)continue;
    int b=a[i];
    (dp[s]+=dp[s-b]*(n-i)%MOD)%=MOD;
    for(int k=s-b-1;k>=0;k--){
      (dp[k+b]+=dp[k])%=MOD;
    }
    dp[a[i]]+=i;
    if(df)print(dp);
  }

  print(dp[s]);
}
