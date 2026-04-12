#include <iostream>
using namespace std;
int n, h, mx, ans;
int main() {
	cin>>n;
	while(n--) {
		cin>>h;
		if(h>=mx) mx = h, ans++;
	}
	cout<<ans;
	return 0;
}