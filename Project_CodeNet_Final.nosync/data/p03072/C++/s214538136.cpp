#include <bits/stdc++.h>
#define inf 1000000000 //1E+9
#define mod 1000000007
using std::cin;
using std::cout;
using std::endl;

int main(){
	int n;cin>>n;
	int h[n];for(int i=0;i<n;i++)cin>>h[i];

	int ans=1;
	int flag=0;
	for(int i=1;i<n;i++){
		flag=1;
		for(int j=0;j<i;j++){
			if(h[j]>h[i])flag=0;
		}
		if(flag)ans++;
	}

	cout<<ans<<endl;

	return 0;
}