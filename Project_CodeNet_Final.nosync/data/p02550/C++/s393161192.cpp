#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX=100001;
typedef long long ll;
int main()
{
  ll n,x,m,a,t,i,res;
  ll d[N_MAX],s[N_MAX];
  cin >> n >> x >> m;
  fill(d,d+m,0);
  s[0]=0;
  a=x;
  s[1]=x;
  d[x]=1;
  for(i=2;i<=n;i++){
    a=(a*a)%m;
    s[i]=s[i-1]+a;
    if(d[a]>0)
      break;
    d[a]=i;
  }
  if(i>n){
    res=s[n];
  }else{
    t=(n-d[a])/(i-d[a]);
    res=t*(s[i]-s[d[a]])+s[n-t*(i-d[a])];
  }
  cout << res << endl;
  return 0;
}