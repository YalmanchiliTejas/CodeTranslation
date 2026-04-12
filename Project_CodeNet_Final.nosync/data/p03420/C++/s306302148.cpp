#include <iostream>
using namespace std;
long long n, k, s;
int main() {
	long long i, j, c, t;
	cin>>n>>k;
	if(k==0) {cout<<n*n; return 0;}
	for(i=k+1, c=1; i<=n; i++, c++) {
		s += n/i * c;
		t = n/i*i+k;
		if(n>=t) s += n-t+1;
	}
	cout<<s;
	return 0;
}