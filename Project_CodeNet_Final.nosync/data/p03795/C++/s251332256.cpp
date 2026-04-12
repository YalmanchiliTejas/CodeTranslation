#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;
	cin >> n;
	int y = (n / 15) * 200;
	cout << 800 * n - y << "\n";
	return 0;
}