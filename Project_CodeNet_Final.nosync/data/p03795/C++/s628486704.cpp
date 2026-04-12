#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

const int Max = 1e5;

int main(){
	int n, m, i, j;
	int ans;
	while(~scanf("%d", &n)){
		ans = n * 800;
		m = n / 15;
		ans -= m * 200;
		cout << ans << endl;
	}
	return 0;
}