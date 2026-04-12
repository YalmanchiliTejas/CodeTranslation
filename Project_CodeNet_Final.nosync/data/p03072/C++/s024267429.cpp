#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int>h(n);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	int ans=0;
	int maxheight=-1;
	for(int i=0;i<n;i++){
		if(maxheight<=h[i]){
			ans++;
			maxheight=h[i];
		}
	}
	cout<<ans<<endl;
}