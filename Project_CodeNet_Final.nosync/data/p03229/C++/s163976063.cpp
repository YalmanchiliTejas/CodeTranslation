#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	int N;
	cin>>N;
	
	vector<long long> A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	
	sort(A.begin(),A.end());
	
	if(N%2==0){
		long long ans = 0;
		for(int i=0;i<(N/2)-1;i++){
			ans -= A[i]*2;
		}
		ans -= A[N/2-1];
		ans += A[N/2];
		for(int i=N/2+1;i<N;i++){
			ans += A[i]*2;
		}
		cout<<ans<<endl;
	}
	else{
		long long a1 = 0,a2 = 0;
		for(int i=0;i<N/2;i++){
			a1 -= A[i]*2;
		}
		a1 += A[N/2] +A[N/2+1];
		for(int i=N/2+2;i<N;i++){
			a1 += A[i]*2;
		}
		
		for(int i=0;i<N/2-1;i++){
			a2 -= A[i]*2;
		}
		a2 -= A[N/2-1] + A[N/2];
		for(int i=N/2+1;i<N;i++){
			a2 += A[i]*2;
		}
		
		cout<<max(a1,a2)<<endl;
	}
	
	return 0;
}