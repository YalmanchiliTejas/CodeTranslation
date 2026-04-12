
#include <bits/stdc++.h>


using namespace std;
double pi=3.14159265358979323846264338;
long long sum;
long long arr[200001];
int main(){
	int n;
	cin>>n;
	long long sum=0;
	long long ans=0;
	long long m=1000000007;
	for(int i=0;i<n;i++){cin>>arr[i];sum+=arr[i];}
	for(int i=0;i<n;i++){
		sum-=arr[i];
		ans+=sum%m*arr[i];
		ans=ans%m;
	}
	cout<<ans<<endl;
	return 0;
}