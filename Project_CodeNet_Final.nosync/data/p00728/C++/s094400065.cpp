#include <iostream>
using namespace std;
int main(){
	int n, s, t, M, m, h;
	while(1){
		cin >> n;
		if(not n) break;
		t = 0;
		M = 0;
		m = 1001;
		for (int i = 0; i < n; ++i){
			cin >> s;
			t += s;
			M = max(M, s);
			m = min(m, s);
		}
		cout << (t-M-m) / (n-2) << endl;
	}
	return 0;
}