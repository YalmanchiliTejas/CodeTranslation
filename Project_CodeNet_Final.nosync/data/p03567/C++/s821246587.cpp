#include<stdio.h>
#include<string.h>

int main() {
    int i;
	bool flag;
	char a[10];
	while(scanf("%s",a)!=EOF) {
		flag = 0;
		for(i=0;i<strlen(a);i++) {
			if(a[i]=='A'&&a[i+1]=='C') {
				flag = 1;
				break;
			}
		}
		if(flag) printf("Yes\n");
		else printf("No\n");
	}
}