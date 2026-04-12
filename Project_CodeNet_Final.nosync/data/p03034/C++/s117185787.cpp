#include<cstdio>

const int MAX_N = 100000;
int s[MAX_N];

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		scanf("%d", &s[i]);
	}
	long long max_score = 0;
	for(int ab=1;ab<=(n-2)/2;ab++) {
		int max_i = (n-2) / ab - 1;
		if((n-1) % ab == 0) {
			int tmp = ((n-1) / ab - 1) / 2;
			if(tmp < max_i) max_i = tmp;
		}
		long long score = 0;
		for(int i=1;i<=max_i;i++) {
			score += s[ab*i] + s[n-1-ab*i];
			if(score > max_score) max_score = score;
		}
	}
	printf("%lld\n", max_score);
	return 0;
}
