#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[105],n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int sum=1;
	int maxv=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]>=maxv){
			sum++;
			maxv=a[i];
		}
	}
	cout<<sum<<endl;
	return 0;
}