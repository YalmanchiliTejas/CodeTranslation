#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int cnt=0;
	multiset<int> mt;
	for(int i=0;i<n;i++){
		auto iter =mt.lower_bound(a[i]);
		if(iter==mt.begin()){
			cnt++;
			mt.insert(a[i]);
		}
		else{
			iter--;
			mt.erase(iter);
			mt.insert(a[i]);
		}
	}
	cout << cnt << endl;
}