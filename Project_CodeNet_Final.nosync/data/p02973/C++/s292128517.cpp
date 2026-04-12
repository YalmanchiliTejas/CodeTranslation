#include <bits/stdc++.h>

using namespace std;

template <class T>inline T updmax(T &a, T b) { return a = max(a, b); }
template <class T>inline T updmin(T &a, T b) { return a = min(a, b); }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n, 0);
	for(int i=0; i<n; i++)cin >> a[i];
	multiset<int> si;
	si.insert(a[0]);
	for(int i=1; i < n; i++){
		auto it = si.lower_bound(a[i]);
		if(it != si.begin()){
			it--;
			si.erase(it);
		}
		si.insert(a[i]);
	}
	cout << si.size() << "\n";
	
	return 0;
}