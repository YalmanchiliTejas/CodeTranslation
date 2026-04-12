#include <bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
typedef pair<int,int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define INF 1000000000000

int MOD=1000000007;
int modpow(int a,int x){
  if(a<0)a+=MOD;
  int ans=1;
  while(x>0){
    if(x&1) ans=ans*a%MOD;
      a=a*a%MOD;
      x>>=1;
  }
  return ans;
}

int gyaku(int n){
    return modpow(n,MOD-2);
}

auto factor(int n){
  map<int,int>res;
  for(int i=2;i*i<=n;i++){
      for(; n%i==0;n/=i) res[i]++;
  }
  if(n>1)res[n]++;
  return res;
}
////////////////////////////////////////////////////////////
signed main() {
  int n;
  cin>>n;
  string mb;
  cin>>mb;
mb.push_back(mb[0]);
  for(int kai=3;kai>=0;kai--){
  vector<int>a(n+2);
  a[0]=kai%2;
  a[1]=(kai/2)%2;
  int t=0;
  rep(i,n){
    if(a[i+1]==1){
      if(mb[i+1]=='o')t=a[i];
      else  if(mb[i+1]=='x')t=1-a[i];
    }
    else{
      if(mb[i+1]=='o')t=1-a[i];
      else t=a[i];
    }

    a[i+2]=t;
}
if(a[n+1]==a[1]&&a[n]==a[0]){
  rep(i,n){
    if(a[i]==0)cout<<'W';
    else cout<<'S';
  }
  exit(0);
}
}
  cout<<-1<<endl;
}
