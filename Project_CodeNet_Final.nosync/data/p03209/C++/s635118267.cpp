#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;++i)
#define mod 1000000007

ll sum[100]={0},pa[100]={0};

ll f(ll N,ll X){//level;N, X以下のpの数
  if(N==0){
    if(X<=0)return 0;
    else return 1;
  }else if(X<=1+sum[N-1])return f(N-1,X-1);
  else if(X==2+sum[N-1])return pa[N-1]+1;
  else if(X>2+sum[N-1] && X<=2+2*sum[N-1]){
    return pa[N-1]+1+f(N-1,X-2-sum[N-1]);
  }else return 2*pa[N-1]+1;
}

int main(){
  ll n,x;
  cin >> n >>x;
  sum[0]=pa[0]=1;
  rep(i,70){
    sum[i+1]=sum[i]*2+3;
    pa[i+1]=pa[i]*2+1;
  }
  cout << f(n,x) << endl;
}
