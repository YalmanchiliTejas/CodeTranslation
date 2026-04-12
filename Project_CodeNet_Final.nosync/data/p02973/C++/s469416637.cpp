#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	multiset < int > arr; int N; cin >> N;
	for(int i = 1 ; i <= N ; ++i){
		int a; cin >> a;
		auto t = arr.lower_bound(a);
		if(t != arr.begin()) arr.erase(--t);
		arr.insert(a);
	}
	cout << arr.size();
	return 0;
}
