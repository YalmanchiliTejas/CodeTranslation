#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	reverse(a, a + n);
	for(int i = 0; i < n; i += 2) cout << a[i] << ' ';
	for(int i = n - 1 - n % 2; i >= 0; i -= 2) cout << a[i] << ' ';
	cout << endl;
}