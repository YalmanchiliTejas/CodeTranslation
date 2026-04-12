#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,ans=1,MAX=0;
	cin>>n;
	int h[n];
	for(int i=0;i<n;i++){
		cin>>h[i];
		if(i==0) continue;
		if(h[MAX]<=h[i]){
			MAX=i;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
