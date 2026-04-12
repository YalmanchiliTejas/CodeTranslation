#include <iostream>
#define llint long long

using namespace std;

llint K, A, B;

int main(void)
{
	cin >> K >> A >> B;
	
	llint ans;
	if(A > B){
		ans = (K-B-1) / (A-B) * 2 + 1;
	}
	else{
		if(A >= K) ans = 1;
		else ans = -1;
	}
	
	cout << ans << endl;
	return 0;
}