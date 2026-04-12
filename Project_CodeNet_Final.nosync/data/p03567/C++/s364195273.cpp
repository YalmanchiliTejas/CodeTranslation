#include<bits/stdc++.h>
#define For(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
int main(){
	char c[10]; scanf("%s",c); int l=strlen(c);
	For(i,0,l-2) if (c[i]=='A'&&c[i+1]=='C') printf("Yes"),exit(0);
	printf("No");
	return 0;
}