#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main()
{
	ll n;
	ll a[50];
	scanf("%lld", &n);
	for(int i=0; i<n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a, a+n, greater<ll>());
  ll ans=0;
  if(a[0]<=1000){
    if(a[0]<=n-1){
      printf("%d\n", 0);
      return 0;
    }
    while(1){
      ll m=-1, im;
      for(ll j=0; j<n; j++){
        if(m<a[j]){
          m=a[j], im=j;
        }
      }
      for(ll i=0; i<n; i++){
        if(im==i){
          a[i]-=n;
        }else{
          a[i]++;
        }
      }
      ans++;
      bool e=0;
      for(ll j=0; j<n; j++){
        if(a[j]>=n){
          e=1;
          break;
        }
      }
      if(e==0){
        break;
      }
    }  
    printf("%lld\n", ans);
    return 0;
  }
	
	for(ll i=1; i<n; i++){
		ll d=(a[0]-a[i])/(n+1);
		for(ll j=0; j<i; j++){
			a[j]-=((n-i+1)*d);
		}
		for(ll j=i; j<n; j++){
			a[j]+=(i*d);
		}
		ans+=(i*d);
	}
  if(a[0]<=n-1){
    printf("%lld\n", ans);
    return 0;
  }
	if(a[0]>=2*n+10){
      ll d=a[0]-2*n-10;
      ans+=(d*n);
      
      for(ll i=0; i<n; i++){
        a[i]-=d;
      }
    }
    while(1){
      ll m=-1, im;
      for(ll j=0; j<n; j++){
        if(m<a[j]){
          m=a[j], im=j;
        }
      }
      for(ll i=0; i<n; i++){
        if(im==i){
          a[i]-=n;
        }else{
          a[i]++;
        }
      }
      ans++;
      bool e=0;
      for(ll j=0; j<n; j++){
        if(a[j]>=n){
          e=1;
          break;
        }
      }
      if(e==0){
        break;
      }
    }
	printf("%lld\n", ans);
	return 0;
}
