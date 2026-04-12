#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int n, t, e, x;
	cin >> n >> t >> e;
	for(int i = 0;i < n;i++){
		cin >> x;
		int k = t / x * x;
		if(abs(k - t) <= e || abs(k + x - t) <= e){
			cout << i + 1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}