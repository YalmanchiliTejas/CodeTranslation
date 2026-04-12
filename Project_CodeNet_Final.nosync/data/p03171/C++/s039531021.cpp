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
const int N = 3e3+9, M = 1e5+9, OO = 0x3f3f3f3f,MOD = 1e9 + 7;
int n;
LL arr[N],memo[N][N][2];
LL solve(int i=0,int j=n-1,int player=0)
{
  if(i>j) return 0;

  LL &ret = memo[i][j][player];
  if(~ret) return ret;
  if(!player) ret = max(arr[i]-solve(i+1,j),arr[j]-solve(i,j-1));
  else  ret = min(solve(i+1,j)-arr[i],solve(i,j-1)-arr[j]); // X-Y
  
  return ret;

}

int main()
{
  memset(memo,-1,sizeof memo);

  scanf("%d",&n);
  for(int i=0;i<n;++i) scanf("%lld",arr+i);
  printf("%lld",solve());

  
  #ifdef _LOCAL_DEFINE
  cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
  #endif
  return 0; 
}