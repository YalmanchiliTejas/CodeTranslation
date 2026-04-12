#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char a[10010];
	int n;
	gets(a);
	n=strlen(a);
	for(int i=0;i<n;i++){
		if(a[i]=='a' or a[i]=='e' or a[i]=='i' or a[i]=='o' or a[i]=='u'){
			printf("vowel");
		}else{
			printf("consonant");
		}
	}
	return 0;
}