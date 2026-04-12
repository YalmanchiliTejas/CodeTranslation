#include<bits/stdc++.h>
using namespace std;
char a[10];
int main(){
	scanf("%s",a);
	int len=strlen(a);
	for(int i=0;i<len-1;i++){
		if(a[i]=='A' && a[i+1]=='C'){
			printf("Yes");
			return 0;
		}
	}
	printf("No");
}