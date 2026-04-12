#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
#define fi first
#define se second
#define pb push_back
#define wzh(x) cerr<<#x<<'='<<x<<endl;
LL n,x,m,s[N],a[N];
int pos[N];
int main() {
  ios::sync_with_stdio(false);
  cin>>n>>x>>m;
  pos[x]=1;s[1]=x;a[1]=x;
  for(int i=2;i<=n;i++){
    a[i]=(a[i-1]*a[i-1])%m;
    if(pos[a[i]]){
      LL last=n-i+1;
      LL duan=i-pos[a[i]];
      cout<<s[i-1]+(last/duan)*(s[i-1]-s[pos[a[i]]-1])+(-s[pos[a[i]]-1]+s[pos[a[i]]-1+(last%duan)])<<'\n';
      return 0;
    }else{
      pos[a[i]]=i;
    }
    s[i]=s[i-1]+a[i];
  }
  cout<<s[n]<<'\n';
  return 0;
}