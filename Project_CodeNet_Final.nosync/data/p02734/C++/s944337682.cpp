#include<iostream>
#include<cstring>
using namespace std;
int N=998244353;
int a[3005][3005],b[3005],n,s;
int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int sum=0;
	for(int i=0;i<n;i++){
		memcpy(a[i+1],a[i],sizeof(a[i]));
		a[i+1][b[i]]=(a[i+1][b[i]]+i+1)%N;
		for(int j=0;j<=s-b[i];j++){
			a[i+1][j+b[i]]=(a[i+1][j+b[i]]+a[i][j])%N;		
		}
		sum=(sum+a[i+1][s])%N;
	}
	cout<<sum;
	return 0;
}
