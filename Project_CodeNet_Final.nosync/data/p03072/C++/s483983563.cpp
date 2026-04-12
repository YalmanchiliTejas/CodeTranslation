#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	int n;
	cin>>n;
	int cnt=1;
	for(int i=0;i<n;i++)cin>>a[i];
	int res=a[0];
	for(int j=0;j<n-1;j++){
		res=max(res,a[j+1]);
		if(a[j+1]>=res)cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}