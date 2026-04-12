#include <bits/stdc++.h>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
int N, A[20], T;

bool valid(int m){
	for(int i = 0; i < m; i++)
		if(A[i] > A[m]) return false;
	return true;
}

int main(void){
	//IO("test.in", "test.out");
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &A[i]);
		if(valid(i)) T++;
	}
	printf("%d\n", T);
}