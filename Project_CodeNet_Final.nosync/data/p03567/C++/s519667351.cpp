#include<bits/stdc++.h>
using namespace std;
int n;
char s[100005];
int main() {
	scanf(" %s",s);
	n = strlen(s);
	for(int i=0;i<n-1;i++) {
		if(s[i]=='A' && s[i+1]=='C'){
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}
