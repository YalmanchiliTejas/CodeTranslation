#include<bits/stdc++.h>
using namespace std;

int main() {
	char s[11];
	scanf("%s", s);
	
	bool chk = false;
	for(int i=1;s[i];i++)
		if(s[i]!=s[i-1]) chk = true;
	puts(chk ? "Yes" : "No");
	
	return 0;
}