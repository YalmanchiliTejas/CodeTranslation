#include<stdio.h>
#include<math.h>

int main(){
    int a,b;
    scanf("%d",&a);
    char s[a],c;
    scanf("%s",s);
    scanf("%d",&b);
    c = s[b - 1];
    for(int i = 0;i < a;i++){
        if(s[i] != c) s[i] = '*';
    }
    printf("%s\n",s);
}