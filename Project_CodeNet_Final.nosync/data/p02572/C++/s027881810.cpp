#include<bits/stdc++.h>
#include<algorithm>
#define int long long
using namespace std;
const int mod=1e9+7; 
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	//MessageBox(GetForegroundWindow(),"标题","内容",MB_YESNO);
	int n;
	cin>>n;
	int a[n+1],f[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=mod;
		f[i]=a[i];
	}
	for(int i=n-1;i>=1;i--){
		f[i]+=f[i+1];
		f[i]%=mod;
	}
	int sum=0;
	for(int i=1;i<=n-1;i++){
		int s=a[i]*f[i+1];
		s%=mod;
		sum+=s;
		sum%=mod;
	}
	cout<<sum<<endl;
	return 0;
}
