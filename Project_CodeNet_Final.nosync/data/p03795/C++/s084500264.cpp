#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	cin >> n;
	
	long long meals = n / 15;
	
	long long x = n * 800;
	long long ans = x - (meals * 200);
	
	cout << ans << endl;
}