#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int ll;

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	ll ans=0;
	for(int i=1;i<n;i++){
		map<int,int> mp;
		ll ret=0;
		for(int j=0;j<n;j+=i){
			if(n-1<j+i)break;
			ret+=a[j];
			mp[j]++;
			if(mp[j]>1)break;
			ret+=a[n-1-j];
			mp[n-1-j]++;
			if(mp[n-1-j]>1)break;
			ans=max(ans,ret);
		}
	}
	cout << ans << endl;
}