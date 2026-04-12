#include <stdio.h>
#include <string.h>

int main(){
char S[100];
scanf("%s",&S);
if (strcmp(S, "AAA")==0 || strcmp(S,"BBB")==0){
printf("No\n");
}
else {
printf("Yes\n");
}
return 0;
}