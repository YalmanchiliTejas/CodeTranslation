#include <bits/stdc++.h>
#define INF 100000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll n;
ll a[51];
ll tmp[51];

bool C(ll v){
	for(int i=0;i<n;i++){
		tmp[i]=a[i]+v;
	}
	ll cnt=0;
	for(int i=0;i<n;i++){
		ll rest=tmp[i]-(n-1LL);
		if(rest<=0)continue;
		cnt+=(rest+n)/(n+1LL);
		if(cnt>v)return false;
	}
	return true;
}

int main(void){
	scanf("%lld",&n);
	ll sum=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	ll l=0,r=INF*INF;
	ll res=INF*INF*50LL;
	while(l+1<r){
		ll mid=(l+r)/2LL;
		bool flag=false;
		for(ll i=mid*n;i<(mid+1LL)*n;i++){
			if(C(i)){
				flag=true;
				res=min(res,i);
			}
		}
		if(flag)r=mid;
		else l=mid;
	}
	for(ll i=l*n;i<=r*n;i++){
		if(C(i)){
			res=min(res,i);
		}
	}
	printf("%lld\n",res);
	return 0;
}