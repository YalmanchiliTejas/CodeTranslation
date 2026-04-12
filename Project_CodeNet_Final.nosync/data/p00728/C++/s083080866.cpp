#include <iostream>
using namespace std;

int n, a[110];

int main(){
	while(cin >> n && n > 0){
		int mins = 1010;
		int maxs = 0;
		int sum = 0;
		for(int i=0; i<n; ++i){
			cin >> a[i];
			mins = min(mins, a[i]);
			maxs = max(maxs, a[i]);
			sum += a[i];
		}
		int ans = (sum - mins - maxs) / (n-2);
		cout << ans << endl;
	}
}
