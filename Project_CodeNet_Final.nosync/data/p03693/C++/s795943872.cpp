#include <bits/stdc++.h>
#define Y "YES"
#define N "NO"
using namespace std;

int a, b, c;
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> a >> b >> c;
	if ((10 * b + c) % 4) cout << N;
	else cout << Y;
}