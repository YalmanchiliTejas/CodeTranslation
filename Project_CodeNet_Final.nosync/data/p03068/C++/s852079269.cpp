#include<bits/stdc++.h>
int main()
{
	int n,k;
	char s[15];
	scanf("%d",&n);
	scanf("%s",s);
	scanf("%d",&k);
	for(int i=0;i<strlen(s);i++){
		if(s[i]!=s[k-1]){
			s[i]='*';
		}
	}
	printf("%s",s);
	return 0;
}