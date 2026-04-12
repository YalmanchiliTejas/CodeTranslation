#include<cstdio>
#include<cstring>
char a[100];
int b[30]={0},c[30]={0};
int main(){
    int n,i,j,t;
    scanf("%d",&n);
    getchar();
    for(i=0;i<n;i++){
        scanf("%s",a);
        t=strlen(a);
        if(i==0){
            for(j=0;j<t;j++){
                b[a[j]-'a']++;
            }
        }
        else{
            for(j=0;j<t;j++){
                c[a[j]-'a']++;
            }
            for(j=0;j<26;j++){
                if(b[j]>c[j])
                    b[j]=c[j];
            }
            memset(c,0,sizeof(c));
        }

    }
    for(i=0;i<26;i++){
      //printf("%d ",b[i]);
            for(j=1;j<=b[i];j++)
                printf("%c",i+'a');
    }
    printf("\n");

    return 0;
}
