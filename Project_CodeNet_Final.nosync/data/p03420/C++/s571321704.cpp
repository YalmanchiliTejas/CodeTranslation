#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	long long int n,k;
	long long int zero = 0;
	cin >> n >> k;
	long long int a = 0;
	if(k == 0){
		cout << (n * n) << endl;
		return 0;
	}
	for(long long int i = k + 1;i <= n;i++){
		a += (n / i) * (i - k) + max(n % i + 1 - k, zero);
	}
	cout << a << endl;
}