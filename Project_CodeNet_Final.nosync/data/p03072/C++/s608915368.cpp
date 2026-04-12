#include <iostream>

using namespace std;

int n;
int a[25];

int main(void)
{
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	int mx = 0, ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] >= mx) ans++;
		mx = max(mx, a[i]);
	}
	cout<< ans << endl;
	return 0;
}