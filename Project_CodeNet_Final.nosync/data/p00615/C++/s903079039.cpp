#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<functional>

using namespace std;

int n, m, t[300000];

int main(){
	
	vector<int> ans;
	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		for (int i = 0; i < n; i++)cin >> t[i];
		for (int i = n; i < m+n; i++)cin >> t[i];
		sort(t, t + n + m);
		int Max = t[0];
		for (int i = 0; i < n + m - 1; i++)Max = max(Max, t[i + 1] - t[i]);
		ans.push_back(Max);
	}
	for (int i = 0; i < ans.size(); i++)cout << ans[i] << endl;
	return 0;
}