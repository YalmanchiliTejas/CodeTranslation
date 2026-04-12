#include <bits/stdc++.h>
using namespace std;
#define popcnt(a) __builtin_popcount(a)

#define error(args...)                       \
{                                            \
    cerr<<"LINE "<<__LINE__;                 \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
    cerr<<endl;                              \
}
void err(istream_iterator<string> it)
{
} 
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr<<' '<< *it << " = " << a ;
  err(++it, args...);
} 
typedef long long ll;
const int N = 3e5+1 , M = 5e5+1, OO = 0x3f3f3f3f,MOD = 1e9+7;
char str[101];
ll memo[101][2][4];
int n,K;
ll solve(int j=0,bool valid=true,int k=K)
{
  if(j==n) return !k;
  if(k<0) return 0;
  ll &ret = memo[j][valid][k];
  if(~ret) return ret;
  ret = 0;
  int m = valid? str[j]-'0':9;
  for(int i=0;i<=m;++i)
  {
    int nwvld = valid && i==m ;
    int nwk= k - (i!=0);

    error(i,nwvld,nwk);
    ret+=solve(j+1,nwvld,nwk);
  
  }
  return ret;

}
int main()
{
  memset(memo,-1,sizeof memo);
  scanf("%s%d",str,&K);
  n=strlen(str);
  printf("%lld",solve());
  #ifdef _LOCAL_DEFINE  
  cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
  #endif
  return 0; 
}