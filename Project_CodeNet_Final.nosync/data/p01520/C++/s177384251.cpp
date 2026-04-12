#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
	int n, t, e;
	cin >> n >> t >> e;
	t -= e;
	int num = -1;
	for (int i = 0; i < n; i++){
		int a;
		cin >> a;
		for (int j = 0; j < e * 2 + 1; j++){
			if ((t + j) % a == 0)num = i + 1;
		}
	}
	cout << num << endl;
	char c;
	cin >> c;
	return 0;
}