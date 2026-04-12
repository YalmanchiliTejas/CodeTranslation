#include<bits/stdc++.h>

using namespace std;
int a[25];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	int ans=0;
	for(int i=0;i<n;i++){
		bool flag=1;
		for(int j=0;j<i;j++){
			if(a[j]>a[i])flag=0;
		}
		if(flag)ans++;
	}
	cout<<ans<<endl;
	return 0;
}