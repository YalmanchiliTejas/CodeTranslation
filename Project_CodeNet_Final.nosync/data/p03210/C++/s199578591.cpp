#include <bits/stdc++.h>
using namespace std;

void solve(long long X){
	if (X == 3 || X == 5 || X == 7) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}

}

int main(){
	long long X;
	scanf("%lld",&X);
	solve(X);
	return 0;
}
