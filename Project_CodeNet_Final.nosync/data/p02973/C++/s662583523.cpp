#include <iostream>
#include <set>
using namespace std;

int n, a, c;
multiset<int> s;
multiset<int>::iterator iter;

int main(){
	cin >> n;
	cin >> a;
	s.insert(a);
	for (int i = 0; i < n-1; ++i){
		cin >> a;
		iter = s.lower_bound(a);
		if (iter != s.begin()) s.erase(--iter);
		s.insert(a);
	}
	cout << s.size();
}