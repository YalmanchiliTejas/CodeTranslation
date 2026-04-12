#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n;
	vector<int> ans;
	cin>>n;
	while(n--) {
		int a;
		cin>>a;
		auto fd = lower_bound(ans.rbegin(), ans.rend(), a);
		if (ans.size() == 0 || fd == ans.rbegin())
			ans.push_back(a);
		else
			*prev(fd) = a;
	}
	cout<<ans.size()<<endl;
	return 0;
}