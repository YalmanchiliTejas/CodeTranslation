#include<stdio.h>
int main()
{
	char X[5];
	scanf("%s",&X);
	
	if(X[0]=='A' && X[1]=='A' && X[2]=='B' || X[0]=='B' && X[1]=='B' && X[2]=='A')
	{
		printf("Yes");
	}
	if(X[0]=='A' && X[1]=='B' && X[2]=='A' || X[0]=='B' && X[1]=='A' && X[2]=='B')
	{
		printf("Yes");
	}
	if(X[0]=='B' && X[1]=='A' && X[2]=='A' || X[0]=='A' && X[1]=='B' && X[2]=='B')
	{
		printf("Yes");
	}
	if(X[0]=='A' && X[1]=='A' && X[2]=='A' || X[0]=='B' && X[1]=='B' && X[2]=='B')
	{
		printf("No");
	}
	
	
	
	
	
	return 0;
}