#include <bits/stdc++.h>
using namespace std;

void solve(long long N, long long X){
	long long A[N+1], P[N+1];
	A[0] = 1;
	P[0] = 1;
	for (int i = 1; i < N+1; i++) {
		A[i] = A[i-1]*2+3;
		P[i] = P[i-1]*2+1;
	}
	long long d = X;
	long long level = N;
	stack<long long> st1, st2;
	st1.push(A[level]);
	st2.push(P[level]);
	long long res = 0;
	while (d > 0) {
		if (d - st1.top() < 0) {
			level--;
			st1.pop();
			st2.pop();
			st1.push(1);
			st1.push(A[level]);
			st1.push(1);
			st1.push(A[level]);
			st1.push(1);
			st2.push(0);
			st2.push(P[level]);
			st2.push(1);
			st2.push(P[level]);
			st2.push(0);
		} else {
			d -= st1.top();
			res += st2.top();
			st1.pop();
			st2.pop();
		}
	}
	printf("%lld\n",res);
}

int main(){
	long long X;
	long long N;
	scanf("%lld",&N);
	scanf("%lld",&X);
	solve(N, X);
	return 0;
}
