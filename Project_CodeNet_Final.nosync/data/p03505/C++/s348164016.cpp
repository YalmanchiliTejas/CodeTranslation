#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int main(){
	ll k,a,b;cin>>k>>a>>b;
	if(a>=k){
		puts("1");
		return 0;
	}
	if(a-b<=0){
		puts("-1");
		return 0;
	}
	ll d=(k/(a-b))*2;d=max(0LL,d-6);
	ll c=d/2*(a-b);
	while(1){
		c+=a;
		d++;
		if(c>=k){
			cout<<d<<endl;
			return 0;
		}
		c-=b;
		d++;
	}
}
