#include <iostream>
#define llint long long

using namespace std;

llint N, K;

int main(void)
{
	cin >> N >> K;
	
	if(K == 0){
		cout << N*N << endl;
		return 0;
	}
	
	llint ans = 0;
	for(int b = K+1; b <= N; b++){
		llint k = N/b;
		ans += k*(b-K);
		ans += max(0LL, N - (k*b+K)+1) ;
	}
	cout << ans << endl;
	return 0;
}