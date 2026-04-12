#include<bits/stdc++.h>
using namespace std;
const int MXN = 100;
int main() {
	int N;
	scanf("%d",&N);
	int H[MXN];
	for(int i = 0; i<N; i++) {
		scanf("%d",H+i);
	}
	int counter = 1;
	int j=0;
	for(int i =1; i<N; i++) {
		for(j =0; j<i; j++) {
			if(H[j]>H[i]) break;

		}
		if(j== i) counter++;
		
	}
	printf("%d", counter);
	return 0;
}