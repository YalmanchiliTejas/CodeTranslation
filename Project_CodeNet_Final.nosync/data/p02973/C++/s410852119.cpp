#include <bits/stdc++.h>
 
using namespace std;
 
#define ALL(x) x.begin(), x.end()
 
typedef long long int lld;
typedef pair<int, int> pii;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(15);
	cout << fixed;
 
	int n = 0;
	cin >> n;

	multiset<int> mt;

	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		
		auto it = mt.lower_bound(x);
		
		if (it != mt.begin()) {
			it--;
			mt.erase(it);
		}

		mt.insert(x);
	}

	cout << mt.size() << '\n';
 
	
 
 
	return 0;
}