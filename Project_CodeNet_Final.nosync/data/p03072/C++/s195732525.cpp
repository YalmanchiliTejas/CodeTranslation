// This  Program is made by Jan(Codezebra)
#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int ans=0;
	int m=0;
	for(int i=0;i<n;i++){
		int h;
		cin>>h;
		if(h>=m){
			ans++;
			m=h;
		}
	}
	cout<<ans;
	return 0;
}

