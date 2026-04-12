#include <bits/stdc++.h>
using namespace std;
#define ALL(A) (A).begin(),(A).end()

int main(void){
	int N;
	cin >> N;
	vector<long long> A(N);
	for(int i=0;i<N;i++)cin >> A[i];
	sort(A.rbegin(),A.rend());
	long long ans = 0;
	if(N%2==0){
		for(int i=0;i<N;i++){
			if(i== (N/2)-1){
				ans += A[i];
			}else if(i== (N/2)){
				ans -= A[i];
			}else if(i < (N/2)){
				ans += 2*A[i];
			}else ans -= 2*A[i];
		}
	}else{
		long long res1 = 0;
		for(int i=0;i<(N/2)-1;i++)res1 += A[i]*2;
		res1 += A[(N/2)-1] + A[N/2];
		for(int i=(N/2)+1;i<N;i++)res1 -=A[i]*2;
		
		long long res2 = 0;
		for(int i=0;i<N/2;i++)res2 += A[i]*2;
		res2 -= A[N/2] + A[(N/2)+1];
		for(int i= (N/2)+2;i<N;i++)res2 -= A[i]*2;
		ans = max(res1,res2);
	}
	cout << ans << endl;
}