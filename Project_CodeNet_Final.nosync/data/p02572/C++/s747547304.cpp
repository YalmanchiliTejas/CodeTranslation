#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

const long long mod=1e9+7;

using namespace std;

int main(){
	
	int n;
	cin >> n;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
		a[i]%=mod;
	}
	vector<long long> s(n);
	long long sum=0;
	for(int i=n-1;i>=0;i--){
		sum+=a[i];
		sum%=mod;
		s[i]=sum;
	}
	long long ans=0;
	for(int i=1;i<n;i++){
		ans+=a[i-1]*s[i]%mod;
	}
	ans%=mod;
	cout << ans << endl;
	return 0;
}
