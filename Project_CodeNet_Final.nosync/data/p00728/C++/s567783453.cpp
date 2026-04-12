#include <iostream>
#include <algorithm>
using namespace std;
   int n1;
int main(){
	while (true){
		cin >> n1;
		int a[n1]; if (n1 <= 0) break;
		for (int i = 0; i < n1; i++){
			cin >> a[i];
		}
		sort(a, a + n1);
		a[0] = { 0 };
		a[n1 - 1] = { 0 };
		for (int i2 = 1; i2 < n1; i2++){
			a[0] += a[i2];
		}
		cout << a[0] / (n1 - 2) << endl;
	}
		return 0;
}
 