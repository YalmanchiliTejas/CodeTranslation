#include <iostream>
#include <string>
#include <vector>
#include<algorithm>
#include <stdio.h>
using namespace std;

int main() {
	int n,data,most=0, ans=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> data;
		if (data >= most) {
			ans++;
			most = data;
		}
	}
	
	cout << ans << endl;
}