#include<stdio.h>
int main(){
	char a;
scanf("%c",&a);
		int f=0;
		if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
			printf("vowel\n");
		}
		if(a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u'){
			printf("consonant\n");
		}

	return 0;
}