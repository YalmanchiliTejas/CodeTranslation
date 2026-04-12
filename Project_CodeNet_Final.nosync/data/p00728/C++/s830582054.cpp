#include<iostream>
#include<set>
using namespace std;

int main() {
	int n, a, sum;
	multiset<int> s;
	multiset<int>::iterator it2;
	while(1) {
		cin >> n;
		if(!n) break;
		s.clear();
		for(int i=0; i<n; ++i) {
			cin >> a;
			s.insert(a);
		}
		s.erase(s.begin());
		s.erase(--s.end());
		sum = 0;
		for(multiset<int>::iterator it=s.begin(); it!=s.end(); ++it) {
			sum += (*it);
		}
		cout << (sum/(n-2)) << endl;
	}
	return 0;
}