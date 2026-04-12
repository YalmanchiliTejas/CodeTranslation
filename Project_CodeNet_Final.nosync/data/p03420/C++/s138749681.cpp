#include <iostream>

using namespace std;


int main(){
	long long res=0;
	long long n, k;
	cin >> n >> k;

	for(int m=k+1; m<=n; m++){
		int full = (n+1) / m;
		res += (m-k)*full;
		if((n+1)%m >= k)
			res += (n+1)%m - k;
		if(k==0)
			res--;
	}

	cout << res << endl;

	return 0;
}
