#include <iostream>
using namespace std;
 
int main() {
	int N,K;cin>>N>>K;
	long long ans = 0;
	for(int k=K+1;k<=N;k++){
		if(K==0)ans += (N/k)*(k-K) + (N%k>K?N%k-K:0);
		else ans += (N/k)*(k-K) + (N%k>=K?N%k-K+1:0);
	}
	cout<<ans<<endl;
	return 0;
}