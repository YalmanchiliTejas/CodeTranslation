#include <stdio.h>
int main(){
char a[100000];
for(int i=0;i<100000;i++)a[i]='\0';
scanf("%s",a);
for(int i=0;a[i]!='\0';i++)if(a[i]=='A'&&a[i+1]=='C'){
printf("Yes\n");
return 0;
}
printf("No\n");
}