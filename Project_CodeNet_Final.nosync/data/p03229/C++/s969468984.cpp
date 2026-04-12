#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<ll>a;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	ll ans=0;
	vector<ll>b;
	for(int i=0;i<n;i++){
		b.push_back(a[i]);
		if(i!=n-1-i){
		b.push_back(a[n-1-i]);
		}
		if(i==n-1-i||i>n-1-i){
			break;
		}
	}
	//cout << b.size()<<endl;
	ll now=b[0];
	for(int i=1;i<n-1;i++){
		ans+=abs(now-b[i]);
		now=b[i];
	}
	ans+=abs(b[n-1]-b[0]);
	ll ans2=ans;
	reverse(a.begin(),a.end());
	ans=0;
	vector<ll>c;
	for(int i=0;i<n;i++){
		c.push_back(a[i]);
		if(i!=n-1-i){
		c.push_back(a[n-1-i]);
		}
		if(i==n-1-i||i>n-1-i){
			break;
		}
	}
	//cout << b.size()<<endl;
	now=c[0];
	for(int i=1;i<n-1;i++){
		ans+=abs(now-c[i]);
		now=c[i];
	}
	ans+=abs(c[n-1]-c[0]);	
	cout << max(ans,ans2);
	// your code goes here
	return 0;
}