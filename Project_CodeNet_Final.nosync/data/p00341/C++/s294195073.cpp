#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a[12];

	for (int i = 0;i < 12;i++){
		cin >> a[i];
	}

	sort(a,a+12);

	for (int i = 0;i < 3;i++){
		for (int j = 0;j < 3;j++){
			if(a[i*4+j] != a[i*4+j+1]){
				cout << "no" << endl;
				return 0;
			}
		}
	}

	cout << "yes" << endl;

	return 0;

}
