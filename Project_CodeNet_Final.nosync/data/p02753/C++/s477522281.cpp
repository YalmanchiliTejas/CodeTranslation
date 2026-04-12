#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	char s[5];
	scanf("%s",s);
	if(s[0]=='A'&&s[1]=='A'&&s[2]=='A'){
		printf("No\n");
	}
	else if(s[0]=='B'&&s[1]=='B'&&s[2]=='B'){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
} 