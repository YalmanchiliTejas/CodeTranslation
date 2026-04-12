#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int x,y,z;
	cin>>x>>y>>z;
	int sum=x/(y+z);
	if((sum*(y+z))+z>x){
		sum--;
	}
	cout<<sum<<endl;
}

signed main(){
	//while(1)
	solve();
}