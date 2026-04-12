#include <iostream>
using namespace std;
int main(void){
	long long int n,a[200010],temp[200010],i,t,s=0;
	cin >> n;
	for (i=0;i<n;i++) {
		cin >> a[i];
	}
	t = 0;
	for (i=n-1;i>0;i--) {
		temp[i] = (a[i] + t)%1000000007;
		t = temp[i];
	}
/*for (i=0;i<n;i++) {
cout<<temp[i]<<'\n';
}*/
	for (i=0;i<n-1;i++) {
		s += a[i]*temp[i+1];
		s = s%1000000007;
//cout<<s<<'\n';
	}
	cout << s << '\n';
}
