#include<bits/stdc++.h>
using namespace std;
char s[4];
int main(){
	scanf("%s",s+1);
	if(s[1]!=s[2]||s[1]!=s[3]||s[2]!=s[3])puts("Yes");
	else puts("No");
}