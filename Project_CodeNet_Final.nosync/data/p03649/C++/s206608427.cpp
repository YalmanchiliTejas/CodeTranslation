#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll a[50],b[50];
int main(){
	int n;scanf("%d",&n);
	rep(i,n)scanf("%lld",&a[i]);
	ll cnt=0;
	while(1){
		bool flag=true;
		rep(i,n){
			ll d=a[i]+(cnt-b[i])-b[i]*n;
			if(d>=n){
				flag=false;
				b[i]+=(d-n+1)/n+!!((d-n+1)%n);
				cnt+=(d-n+1)/n+!!((d-n+1)%n);
			}
		}
		if(flag)break;
	}
	printf("%lld\n",cnt);
}
