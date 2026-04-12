#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int b[200][55];
char a[100];
int main(){
    memset(b,0,sizeof(b));
    int n;
    scanf("%d",&n);
    for(int j = 0; j < n; j++){
        scanf("%s",a);
        for(int i = 0; i < strlen(a); i++)
            b[a[i]][j]++;
    }
    for(int i = 0; i < 200; i++){
        sort(b[i],b[i]+n);
        while(b[i][0]--){
            printf("%c",i);
        }
    }
    return 0;
}
