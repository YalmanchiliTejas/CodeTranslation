#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i%15==0){
			ans-=200;
		}
		ans+=800;
	}
	cout<<ans<<endl;
	return 0;
}