#include<cstdio>
char ch[10000];

int main(){
    scanf("%s", ch);
    for(int i = 1; ch[i] != '\0'; i ++)
        if(ch[i-1] == 'A' && ch[i] == 'C'){
            printf("Yes");
            return 0;
        }
    printf("No");
    return 0;
}
