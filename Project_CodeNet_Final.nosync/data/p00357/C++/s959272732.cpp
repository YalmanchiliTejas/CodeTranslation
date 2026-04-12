#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	int d[300005];
	for (int i = 0;i < n;i++){
		cin >> d[i];
	}

	if(d[n-1] < 10 || d[0] < 10){cout << "no" << endl; return 0; } 

	for (int i = 0;i < n;i++){
		if(d[i] < 10){
			int t = 10;
			for (int j = i-1;j >= 0;j--){
				t += 10;
				if(d[j] >= t) break;
				if(j == 0){ cout << "no" << endl; return 0;}
			}
			t = 10;
			for (int j = i+1;j < n;j++){
				t += 10;
				if(d[j] >= t) break;
				if(j == n-1){ cout << "no" << endl; return 0;}
			}
		}
	}

	cout << "yes" << endl;

	return 0;

}


