#include<stdio.h>
#include<string.h>

char s[100][100];

int n;
long long count[50],count2[50];

int main(void){
    int i,j,l;
    scanf("%d",&n);

    for(i = 0;i < n;i++){
        scanf("%s",&s[i][0]);
    }

    for(i = 0;i < 'z' - 'a' + 1;i++)
        count[i] = 10000;
    for(i = 0;i < n;i++){
        l = strlen(&s[i][0]);
        for(j = 0;j < 50;j++)
            count2[j] = 0;
        for(j = 0;j < l;j++){
            count2[s[i][j] - 'a']++;
        }
        for(j = 0;j < 'z' - 'a' + 1;j++)
            if(count[j] > count2[j])
                count[j] = count2[j];
    }
    for(i = 0;i < 'z' - 'a' + 1;i++)
        for(j = 0;j < count[i];j++)
            printf("%c",i + 'a');
    printf("\n");
    return 0;
}