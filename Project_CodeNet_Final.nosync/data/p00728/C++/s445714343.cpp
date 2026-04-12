#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	while(cin>>n){
		if(n==0)break;
		int a[n];
		int M=0,m=1e5;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int sum=0;
		for(int i=0;i<n;i++){
			M=max(a[i],M);
			m = min(a[i],m);
			sum+=a[i];
		}
		sum-=(M+m);
		cout<<sum/(n-2)<<endl;
	}
}
