#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
  ll n;
  ll a[100], x, ans, tmp[100];
  while(cin>>n){
    for(int i=0; i<n; ++i){
      scanf("%lld",&a[i]);
    }
    x=0;ans=0;
    while(1){
      for(int i=0; i<n; ++i){
        tmp[i]=a[i]/n;
        a[i]=a[i]-tmp[i]*n;
        x+=tmp[i];
      }
      ans+=x;
      if(x==0)
        break;
//      cout<<x<<"::"<<endl;
      for(int i=0; i<n; ++i){
        a[i]+=x-tmp[i];
//        cout<<a[i]<<" ";
      }
//      cout<<endl;
      x=0;
    }
    cout<<ans<<endl;
  }
  return 0;
}


