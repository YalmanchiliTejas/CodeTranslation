#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){ cin >> a[i]; }
	deque<int> b;
	for(int i = 0; i < n; ++i){
		if(i % 2 == 0){
			b.push_back(a[i]);
		}else{
			b.push_front(a[i]);
		}
	}
	if(n % 2 == 1){ reverse(b.begin(), b.end()); }
	for(int x : b){
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

