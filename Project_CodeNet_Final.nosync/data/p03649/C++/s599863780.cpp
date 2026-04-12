#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main() {
	int n;cin>>n;
	vector<ll> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int flag=0;
	long long num=0;
	long long ans=0;
	while(1){
		flag=1;
		for(int i=0;i<n;i++){
			a[i]+=num;

		}
		num=0;
		for(int i=0;i<n;i++){
			long long add=a[i]/n;
			num+=add;
			a[i]-=add*(n+1);
//			cout<<a[i]<<' ';
		}
//		cout<<endl;
		if(num==0){
			break;
		}else{
			ans+=num;
		}
	}
	cout<<ans<<endl;
	return 0;
}