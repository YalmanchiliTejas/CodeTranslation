#include <iostream>
#include <algorithm>
using namespace std;
int a[1000006], b[1000006];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(a + 1, a + 1 + n);
	int mid1 = a[n / 2], mid2 = a[n / 2 + 1];
	for (int i = 1; i <= n; ++ i)
		if (b[i] <= mid1)
			cout << mid2 << endl;
		else
			cout << mid1 << endl;
}
