#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<bitset<20> > bit((1 << n), bitset<20>(0));
	for(int i = 0; i < (1 << n); i++) {
		printf("%d:", i);
		for(int j = 0; j < n; j++) {
			if(i & (1 << j))
				printf(" %d", j);
		}
		printf("\n");
	}
}

