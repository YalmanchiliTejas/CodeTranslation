#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	multiset<int> s;
	vector<int> v(n);
	for (int i=0; i<n; ++i){
		cin >> v[i];
	}
	for (int i=0; i<n; ++i){
		if (s.empty() or v[i] <= *s.begin()){
			s.emplace(v[i]);
		}
		else if (*s.rbegin() < v[i]){
			s.erase(s.find(*s.rbegin()));
			s.emplace(v[i]);
		}
		else{
			auto it=s.lower_bound(v[i]);
			it--;
			s.erase(it);
			s.emplace(v[i]);
		}
	}
	cout << s.size();
}
