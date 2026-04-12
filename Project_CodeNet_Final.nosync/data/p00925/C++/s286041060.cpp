#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char str[50];
	int arr[50];
	int top;
	int len;
	int num;
	int ans1,ans2;
	scanf("%s",str);
	scanf("%d",&num);
	len=strlen(str);
	arr[0]=str[0]-'0';
	top=0;
	for(int i=1; i<len; i+=2){
		if(str[i]=='*'){
			arr[top]*=str[i+1]-'0';
		}else{
			arr[++top]=str[i+1]-'0';
		}
	}
	ans1=0;
	for(int i=0; i<=top; i++)
		ans1+=arr[i];
	ans2=str[0]-'0';
	for(int i=1; i<len; i+=2){
		if(str[i]=='*')
			ans2*=str[i+1]-'0';
		else
			ans2+=str[i+1]-'0';
	}
	if(ans1==num && ans2==num)
		printf("U\n");
	else if(ans1==num && ans2!=num)
		printf("M\n");
	else if(ans1!=num && ans2==num)
		printf("L\n");
	else if(ans1!=num && ans2!=num)
		printf("I\n");
	
	
	return 0;
}