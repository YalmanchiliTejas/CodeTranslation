#include<iostream>
using namespace std;

int main(){
	char s[10];
	scanf("%s",s);
	bool flag=false;
	for(int i=1;s[i]!='\0';i++){
		if(s[i]=='C'&&s[i-1]=='A')
			flag=true;
	}
	if(flag)
		puts("Yes");
	else
		puts("No");
	return 0;
}