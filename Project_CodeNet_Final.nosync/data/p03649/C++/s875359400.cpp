#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<ll> a;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.pb(x);
	}
	bool fl = true;
	ll ans = 0;
	while(fl){
		fl = false;
		for(int i=0;i<n;i++){
			if( a[i] >= n){
				ll cnt = a[i]/n;
				ans += cnt;
				a[i]=a[i]%n;
				for(int j=0;j<n;j++){
					if(i!=j)a[j]+=cnt;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(a[i]>=n)fl =true;
		}
	}
	cout<<ans<<endl;
}