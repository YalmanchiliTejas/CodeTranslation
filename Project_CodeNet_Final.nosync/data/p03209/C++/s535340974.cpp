#include<bits/stdc++.h>
using namespace std;
long long s[128], p[128];
long long solve(int n, long long x){
	if(n == 0)
		return 1;
	else if(x == 1)
		return 0;
	if(x > 1 && x <= 1 + s[n - 1])
		return solve(n - 1, x - 1);
	else if(x == s[n - 1] + 2)
		return p[n - 1] + 1;
	else if(x > s[n - 1] + 2 && s[n] > x)
		return p[n - 1] + 1 + solve(n - 1, x - s[n - 1] - 2);
	else if(x == s[n])
		return p[n];
	
}
int main(){
	int n;
	long long x;
	cin >> n >> x;
	s[0] = 1, p[0] = 1;
	for(int i = 1; i <= n; i++){
		s[i] = 2 * s[i - 1] + 3;
		p[i] = 2 * p[i - 1] + 1;
	}
	cout << solve(n, x);
}