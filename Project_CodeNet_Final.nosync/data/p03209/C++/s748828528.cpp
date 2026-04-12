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
  LL n;
  cin >> n;
  LL x;
  cin >> x;
  vector<LL> d(n+1),p(n+1);
  d[0]=p[0]=1;
  for(int i=0;i<n;i++) d[i+1]=2*d[i]+3;
  for(int i=0;i<n;i++) p[i+1]=2*p[i]+1;
  LL ans=0;
  LL now=n;
  while(x>0){
    if(now==0&&x==1){
      ans++;
      break;
    }
    if(x<=1){
      break;
    }else if(x<=d[now-1]+1){
      x-=1;
      now--;
    }else if(x<=d[now-1]+2){
      ans+=p[now-1]+1;
      break;
    }else if(x<=2*d[now-1]+2){
      x-=d[now-1]+2;
      ans+=p[now-1]+1;
      now--;
    }else{
      ans+=p[now];
      break;
    }
  }
  cout << ans << endl;
  return 0;
}
