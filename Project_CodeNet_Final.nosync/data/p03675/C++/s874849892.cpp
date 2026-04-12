
#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);

	deque<int> d;

	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(i % 2 == 0){
			d.push_back(x);
		}else{
			d.push_front(x);
		}
	}

	if(n % 2 == 0){
		for(int i = 0; i < n; i++){
			cout << d[i] << ' ';
		}
	}else{
		for(int i = n - 1; i >= 0; i--){
			cout << d[i] << ' ';
		}
	}
	cout << endl;

	return 0;
}
