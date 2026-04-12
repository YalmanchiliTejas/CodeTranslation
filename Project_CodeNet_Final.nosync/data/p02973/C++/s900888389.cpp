#include <iostream>
#include <set>

using namespace std;
int n,a[100010];
bool solve(int k){
	multiset<int> m;
	for(int i=0;i<k;i++){
		m.insert(-1);
	}
	for(int i=0;i<n;i++){
		int x = *m.begin();
		if(x>=a[i]) return false;
		auto it = m.lower_bound(a[i]);
		it--;
		m.erase(it); m.insert(a[i]);
	}
	return true;
}

int main(){
	int i;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	int l = 0,r = n;
	while(r - l>1){
		int mid = (l + r)/2;
		if(solve(mid)) r = mid;
		else l = mid;
	}
	cout << r << endl;
}