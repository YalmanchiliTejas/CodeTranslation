#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int inf = 1e9;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	vector<vector<bool> > used(n, vector<bool>(n, false));
	int ans = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(used[i][j]) continue;
			used[i][j] = true;
			int diff = a[j] -a[i];
			int sub = 2;
			int prev = j;
			for(int k=a[j]+diff; ; k+=diff){
				auto itr = lower_bound(a.begin(), a.end(), k);
				if(itr == a.end() || *itr != k) break;
				used[prev][itr-a.begin()] = true;
				prev = itr-a.begin();
				sub++;
			}
			ans = max(ans, sub);
		}
	}
	cout << ans << endl;
	return 0;
}
