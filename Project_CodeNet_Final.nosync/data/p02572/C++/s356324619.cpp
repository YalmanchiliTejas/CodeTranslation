#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,N) for(int i=0;i < (N);i++)
using namespace std;

int main(){
	int mod = 1000000007;
	long long N;
	long long sum=0;
	cin>>N;
	vector<long long> A(N);
	rep(i,N){
		cin>>A[i];
		sum+=A[i];
		sum%=mod;
	}
	long long ans=0;
	rep(i,N){
		sum-=A[i];
		if(sum<0)sum+=mod;
		ans+=sum*A[i];
		ans%=mod;
	}
	cout<<ans<<endl;
}