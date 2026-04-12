#include<iostream>
using namespace std;
typedef long long ll;
int n,k;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	ll ans=0;
	for(int i=k+1; i<=n ;i++){
		if(n%i>=k){
			ans+=1LL*((n-k)/i)*(i-k)+n%i-k+1;
		}
		else{
			ans+=1LL*((n-k)/i+1)*(i-k);
		}
	}
	if(k==0) ans-=n;
	cout << ans << endl;
}