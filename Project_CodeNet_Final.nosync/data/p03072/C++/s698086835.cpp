#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF=1e18,MOD=1e9+7;
int main(){
	int n;
	cin>>n;
	vector<int>h(n);
	for(int i=0;i<n;i++)cin>>h[i];
	int ans=0;
	bool flag;
	ans++;
	for(int i=1;i<n;i++){
		flag=true;
		for(int j=0;j<i;j++){
			if(h[i]<h[j])flag=false;
		}
		if(flag)ans++;
	}
	cout<<ans<<endl;
}
