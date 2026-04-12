#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[101],sum,n;
	while(cin>>n,n){
	sum=0;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)if(i!=0&&i!=n-1)sum+=a[i];
	cout<<sum/(n-2)<<endl;
	}
	return 0;
}