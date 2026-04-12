#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
#include <cmath>
using namespace std;

long int paty(int l){
	return ((long int)pow(2,l+1)) - 1;
}

long int all(int l){
	return ((long int)pow(2,l+2)) - 3;
}

long int ans(int n, long int x){
	if (n == 0)
		return 1;
	long int alpha = all(n-1);
	if (x <= 1)
		return 0;
	else if (x < alpha + 1)
		return ans(n-1,x-1);
	else if (x == alpha + 1)
		return paty(n-1);
	else if (x == alpha + 2)
		return paty(n-1) + 1;
	else if (x < 2 * alpha + 2)
		return paty(n-1) + 1 + ans(n-1, x - alpha - 2);
	else 
		return paty(n);
}

int main(){
	int N;
	long int X;
	cin >> N >> X;
	cout << ans(N,X) << endl;
}