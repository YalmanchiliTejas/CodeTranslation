#include "bits/stdc++.h"
using namespace std;
typedef long long int Int;
int N;
char s[100001];
int ans[100010];
bool check(int t0,int t1) {
	ans[0]=t0;
	ans[1]=t1;
	for(int i=1;i<N;i++) {
		if(ans[i]) {
			if(s[i]=='o') ans[i+1]=ans[i-1];
			else ans[i+1]=!(ans[i-1]);
		}else {
			if(s[i]=='x') ans[i+1]=(ans[i-1]);
			else ans[i+1]=!(ans[i-1]);
		}
	}
	if(ans[N]!=ans[0]) return 0;
	if(ans[0]) {
		if(s[0]=='o'&&(ans[1]==ans[N-1])) return 1;
		if(s[0]=='x'&&(ans[1]!=ans[N-1])) return 1;
	}else {
		if(s[0]=='o'&&(ans[1]!=ans[N-1])) return 1;
		if(s[0]=='x'&&(ans[1]==ans[N-1])) return 1;
	}
	return 0;
}
int main() {
	scanf("%d",&N);
	scanf("%s",s);
	for(int i=0;i<=1;i++) {
		for(int j=0;j<=1;j++) {
			if(check(i,j)) {
				for(int k=0;k<N;k++) {
					if(ans[k]) putchar('S'); else putchar('W');
				}
				putchar('\n');
				return 0;
			}
		}
	}
	printf("-1\n");
}