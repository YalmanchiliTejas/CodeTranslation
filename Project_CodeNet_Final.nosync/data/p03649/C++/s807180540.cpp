#include <iostream>
#define llint long long int

using namespace std;

llint N;
llint a[55];
llint next_a[55];

int main(void)
{
	cin >> N;
	for(llint i = 0; i < N; i++){
		cin >> a[i];
	}
	
	bool flag;
	llint ans = 0;
	
	while(1){
		flag = true;
		for(llint i = 0; i < N; i++){
			if( a[i] > N-1 ){
				flag = false;
				break;
			}
		}
		if(flag) break;
		
		for(llint i = 0; i < N; i++) next_a[i] = 0;
		for(llint i = 0; i < N; i++){
			llint val = a[i] / N;
			a[i] %= N;
			ans += val;
			
			for(llint j = 0; j < N; j++){
				if(i == j) continue;
				next_a[j] += val;
			}
		}
		for(llint i = 0; i < N; i++) a[i] += next_a[i];
	}
	
	cout << ans << endl;
	return 0;
}