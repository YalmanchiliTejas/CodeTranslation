#include <bits/stdc++.h>

using namespace std;

int A, B, C, X, Y;

int main(){
	scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y);
	C *= 2;
	bool ok = (C < (A + B));
	int res = 0;
	if(ok){
		int k = min(X, Y);
		res += k * C;
		X -= k, Y -= k;
	}
	int val = (C < A) ? C : A;
	res += X * val;
	val = (C < B) ? C : B;
	res += Y * val;
	printf("%d\n", res);
	return 0;
}