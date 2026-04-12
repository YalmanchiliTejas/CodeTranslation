#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n;
	cin >> n;
	int mx=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		mx=max(mx,x);
		ans+=x==mx;
	}
	cout << ans;
	return 0;
}