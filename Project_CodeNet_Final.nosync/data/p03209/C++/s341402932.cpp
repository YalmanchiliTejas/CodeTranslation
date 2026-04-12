#include <bits/stdc++.h>
#define rep(i, n) for(int i=0;i<(int)(n);++i)
#define rep1(i, n) for(int i=1;i<=(int)(n);++i)
#define irep(i, a, n) for(int i=a;i<(int)(n);++i)
#define rrep(i, n) for(int i=(int)(n)-1;i>=0;--i)
#define allrep(V, v) for(auto&& V:v)
#define all(x) (x).begin(),(x).end()
typedef long long lint;
const int INF=1<<29;
const double EPS=1e-9;
using namespace std;


vector<lint> total, patty;

lint solve(int n, lint w)
{
  if(n == 0){
    return 1;
  }else if(w == 1){
    return 0;
  }else if(w <= total[n-1]+1){
    return solve(n-1, w-1);
  }else if(w == total[n-1]+2){
    return patty[n-1] + 1;
  }else if(w < total[n-1]*2+2){
    return solve(n-1, w-total[n-1]-2) + patty[n-1] + 1;
  }else{
    return patty[n-1] * 2 + 1;
  }
}

int main(void)
{
  int n; cin>>n;
  lint w; cin>>w;
  total.resize(n+1); patty.resize(n+1);
  total[0]=1; patty[0]=1;
  rep1(i,n){
    total[i]=total[i-1]*2+3;
    patty[i]=patty[i-1]*2+1;
  }
  cout << solve(n, w) << endl;
}
