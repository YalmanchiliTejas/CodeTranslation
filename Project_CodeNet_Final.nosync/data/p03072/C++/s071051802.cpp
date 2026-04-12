#include <bits/stdc++.h>
using namespace std;

int n;
int a;
int maxx,ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		maxx=max(maxx,a);
		if(a>=maxx){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}