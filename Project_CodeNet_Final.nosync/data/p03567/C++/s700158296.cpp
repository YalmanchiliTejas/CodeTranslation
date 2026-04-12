#include<bits/stdc++.h>
using namespace std;
char s[100];
int l;
int main(){
	cin>>s;l=strlen(s);for (int i=1;i<l;i++)
		if (s[i-1]=='A'&&s[i]=='C'){puts("Yes");return 0;}
	puts("No");
}