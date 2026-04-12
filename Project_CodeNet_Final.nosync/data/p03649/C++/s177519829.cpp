#include<bits/stdc++.h>
#define ll long long
#define N 55
using namespace std;

int n;
ll a[N],ans;

int main() {

  scanf("%d",&n);
  for(int i=0;i<n;i++) {
    scanf("%lld",&a[i]);
  }
  bool flag=true;
  while(flag) {
    flag=false;
    for(int i=0;i<n;i++) {
      if(a[i]<n) continue ;
      flag=true;
      ll dv=a[i]/n;
      a[i]%=n;
      ans+=dv;
      for(int j=0;j<n;j++) {
        if(i!=j) {
          a[j]+=dv;
        }
      }
    }
  }
  printf("%lld",ans);

}
