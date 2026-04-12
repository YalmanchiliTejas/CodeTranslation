#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, x;
	vector <int> A, B;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &x);
		A.push_back(x);
		B.push_back(x);
	}
	sort(A.begin(), A.end());
	int a = A[(n / 2) - 1];
	int b = A[n / 2];
	for(int i = 0; i < n; ++i){
		if(B[i] <= a) printf("%d\n", b);
		else printf("%d\n", a);
	}
	return 0;
}
