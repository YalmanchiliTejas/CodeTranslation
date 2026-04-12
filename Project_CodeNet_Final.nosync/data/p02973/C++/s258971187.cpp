#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int main(void) {
	int n;
	while(cin >> n) {
		while(n--) {
			int x;
			cin >> x;
			vector<int>::iterator it = upper_bound(v.begin(), v.end(), x, greater<int>());
			if(it == v.end())
				v.push_back(x);
			else
				*it = x;
		}
		cout << v.size() << endl;
	}
}
