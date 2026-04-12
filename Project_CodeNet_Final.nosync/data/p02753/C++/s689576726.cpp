#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
char ch[5];

int main(){
scanf("%[^\n]", &ch);
if((ch[0]==ch[1])&&(ch[1]!=ch[2])||((ch[1]==ch[2])&&ch[0]!=ch[1])||(ch[0]==ch[2]&&ch[0]!=ch[1]))
        printf("Yes");
else
    printf("No");

return 0;
}
