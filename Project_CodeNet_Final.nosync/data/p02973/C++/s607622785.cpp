#include<bits/stdc++.h>
using namespace std;

int main() {
	
	int n; cin>>n;
	deque<int>a;
	int b; cin >> b;
	a.push_back(b);
	for(int i=1; i<n; i++) {
		int b; cin >> b;
		auto it = lower_bound(a.begin(), a.end(), b);
		if(it==a.end()) {
			if(a.back()<b) a.back()=b;
			else a.push_back(b);
		}
		else {
			if(it==a.begin()) a.push_front(b);
			else *(it-1) = b;
		}
	}
	cout << a.size() << endl;
}
