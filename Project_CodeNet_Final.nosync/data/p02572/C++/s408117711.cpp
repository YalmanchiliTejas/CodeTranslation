#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MOD = 1000000007;
int main(){
	long long int N,ans=0;
	cin>>N;
	long long int A[N];
	long long int sA[N];
	for(int i=0;i<N;i++){
		cin>>A[i];
		if(i>0)sA[i]=(sA[i-1]+A[i])%MOD;
		else sA[i]=A[i];
	}
	for(int i=1;i<N;i++){
		ans=(ans+sA[i-1]*A[i]%MOD)%MOD;
	}
	cout<<ans;
	return 0;
}