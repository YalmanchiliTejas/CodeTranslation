#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	vector<int> b(a);
	sort(b.begin(), b.end());
	for(int i = 0; i < n; ++i){
		const int k = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		if(k <= n / 2 - 1){
			cout << b[n / 2] << endl;
		}else{
			cout << b[n / 2 - 1] << endl;
		}
	}
	return 0;
}

