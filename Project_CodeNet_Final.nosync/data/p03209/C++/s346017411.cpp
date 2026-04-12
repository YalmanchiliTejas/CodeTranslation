
#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
	int n;cin>>n;
	long long x;cin>>x;
	vector<ll> lp(n+1),lm(n+1),ln(n+1);
	lp[0]=1;
	lm[0]=1;
	ln[0]=1;
	for(int i=1;i<n+1;i++){
		lp[i]=lp[i-1]*2+1;
		lm[i]=ln[i-1]+2;
		ln[i]=ln[i-1]*2+3;
	}
	ll ans=0;
//	for(auto x:lm){
//		cout<<x<<endl;
//	}
	while(n){
		if(lm[n]==x){
			ans+=lp[n-1]+1;
			break;
		}
		if(x==1){
			break;
		}
		if(x==ln[n]){
			ans+=lp[n-1]*2+1;
			break;
		}
		if(x>lm[n]){
			x-=lm[n];
			ans+=lp[n-1]+1;
		}else{
			x-=1;
		}
		n-=1;
//		cout<<n<<' '<<x<<' '<<ans<<endl;
		if(n==0){
			ans++;
			break;
		}

	}
	cout<<ans<<endl;

	return 0;
}