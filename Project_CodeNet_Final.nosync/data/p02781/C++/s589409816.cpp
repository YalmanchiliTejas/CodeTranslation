#include<bits/stdc++.h>
using namespace std;

#define ran 111

char s[ran];
int len;

int k;

int calc(int len, int todo) {
	if(len<todo) return 0;
	if(todo<0) return 0;
	
	int res = 1;
	for(int i=0;i<todo;i++)
		res = res * (len-i) / (i+1) * 9;
	//printf("%d %d %d\n", len, todo, res);
	return res;
}

int main() {
	scanf("%s", s);
	len = strlen(s);
	scanf("%d", &k);
	
	int done = 0;
	int ans = 0;
	for(int i=0;i<len && done<=k; i++) {
		if(s[i]=='0') continue;
		
		ans += calc(len-i-1, k-done);
		if(s[i]>'1') 
			ans += calc(len-i-1, k-done-1) * (s[i]-'0'-1);
		done++;
	}
	if(done==k) ans++;
	printf("%d\n", ans);
	
	return 0;
}