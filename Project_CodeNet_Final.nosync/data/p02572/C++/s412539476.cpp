#include <cstdio>
#define int long long
int n;
long long ans,a[200005],sum;
signed main(){
  scanf("%lld",&n);
  for(int i=1; i<=n; i++){
    scanf("%lld",&a[i]);
    if(a[i]==0){
      n--;
      i--;
      continue;
    }
    a[i]%=1000000007;
    sum+=a[i];
    sum%=1000000007;
  }
  for(int i=1; i<n; i++){
    sum-=a[i]%1000000007;
    if(sum<0) sum+=1000000007;
    ans=(ans+(sum*a[i]+1000000007)%1000000007)%1000000007;
  }
  printf("%lld",ans);
  return 0;
}