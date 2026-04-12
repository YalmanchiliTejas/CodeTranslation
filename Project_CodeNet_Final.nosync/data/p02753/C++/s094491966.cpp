#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	if((getchar()+getchar()+getchar())%3==0)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}