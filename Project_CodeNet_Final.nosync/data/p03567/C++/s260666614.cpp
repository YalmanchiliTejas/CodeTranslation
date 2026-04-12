#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char a[6];
int main(){
	cin>>a;
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='A'&&a[i+1]=='C'){
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}