#include<cstdio>
int main(){
	char a;
	bool f=false;
	while(scanf("%c",&a)!=EOF){
		if(a=='A')
			f=true;
		if(a=='C'&&f){
			printf("Yes\n");
			return 0;
		}
		if(a!='A'&&a!='C')f=false;
	}
	printf("No\n");
}