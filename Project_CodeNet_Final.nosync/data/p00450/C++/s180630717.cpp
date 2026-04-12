//AOJ 0527: Setting Go Stones 
#include <iostream>
using namespace std;
int n, stones[100001], ans;
int main() {
	while (cin >> n){
		if (n == 0)
			break;
		for (int i = 1; i <= n; i++){
			cin >> stones[i];
			if (i % 2 == 0 && i != 1 && stones[i] != stones[i - 1]){
				for (int j = i - 1; j > 0; j--){
					if (stones[j] == stones[i])
						break;
					stones[j] = stones[i];
				}
			}
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			if (stones[i] == 0)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}