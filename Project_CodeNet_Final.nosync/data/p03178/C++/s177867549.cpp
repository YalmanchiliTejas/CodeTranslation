#include <bits/stdc++.h>
using namespace std;
#define popcnt(a) __builtin_popcount(a)
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
#define IO() freopen("palindrome.in","rw",stdin)
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
typedef long long LL;
const int N = 1e4+9, M = 1e2+9, OO = 0x3f3f3f3f,MOD = 1e9 + 7;
int n,d;
char a[N];
LL memo[N][M][2];
LL solve(int i,int sum,bool last)
{
  
  if(i==n) return (sum==0);

  LL &ret = memo[i][sum][last];
  if(~ret) return ret;

  ret = 0;
  int limit=-1;

  if(!last) limit = 9;
  else limit = (a[i]-'0');

  for(int j=0;j<=limit;++j) ret += solve(i+1,(sum+j)%d, last && (j==limit))%MOD;
  

  return ret%MOD;
}
int main()
{
  memset(memo,-1,sizeof memo);
  scanf("%s",a);
  scanf("%d",&d);
  
  n=strlen(a);

  printf("%lld",(solve(0,0,1)-1 + MOD)%MOD ); 

  #ifdef _LOCAL_DEFINE  
  cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
  #endif
  return 0; 
}

