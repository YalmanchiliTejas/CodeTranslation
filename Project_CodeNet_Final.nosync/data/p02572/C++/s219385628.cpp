#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
const int MOD = 1000000007,N = 200010;
long long n,a[N],b[N];
int main(){
//	freopen("1.txt","r",stdin);
	long long s=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
		s%=MOD; 
		b[i+1]=s;
	}
	b[0]=0;
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=b[i]*a[i]%MOD;
		sum%=MOD;
	}
	cout<<sum<<endl;
	return 0;
}


