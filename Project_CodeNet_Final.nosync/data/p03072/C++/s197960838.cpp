#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, x, max, cnt;
	cin >> n;
	vector<int> h;
	for(int i=0; i<n; i++){
		cin >> x;
		h.push_back(x);
	}
	max = 0;
	cnt = 0;
	for(int i=0; i<n; i++){
		if(h[i] >= max){
			cnt++;
			max = h[i];
		}
	}
	cout << cnt << endl;
	return 0;
}
