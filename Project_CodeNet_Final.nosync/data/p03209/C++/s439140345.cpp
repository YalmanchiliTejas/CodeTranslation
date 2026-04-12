#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll> p(51),al(51);


int main(){
	ll n,x;
	cin>>n>>x;
	p[0] =al[0] = 1;
	for(int  i= 1;i<n+1;i++){
		p[i] = p[i-1]*2+1;
		al[i] = al[i-1]*2+3;
		//cout<<p[i]<<' '<<al[i]<<endl;
	}
	ll ans = 0;

	while(x>0&&n>=0){
		if(x>=al[n]){
		//cout<<n<<endl;
		x-=al[n];
		ans+=p[n];
			if(x>0){
				x--;
				ans++;
			}
		}else{
		x--;
		n--;
		}
	}
	cout<<ans<<endl;
	return 0;
}
