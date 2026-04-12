#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main () {
    int n,m;
    char a[109][109];
    int b[102];
    int c[120];
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    scanf("%d %d",&n,&m);
     for(int i=0;i<n;i++){
            getchar();
        for(int j=0;j<m;j++){
            scanf("%c",&a[i][j]);
        }

    }
    //printf("\n\n");
   for(int i=0;i<n;i++){
        int k=0;
        for(int j=0;j<m;j++){
                if(a[i][j]=='.'){
                 k++;
                }
            }
        if(k==m){
            b[i]=1;
        }
    }
    for(int j=0;j<m;j++){
        int k=0;
        for(int i=0;i<n;i++){
            if(a[i][j]=='.'){
                k++;
            }
            }if(k==n){
                c[j]=1;
        }
    }

    for(int i=0;i<n;i++){
            int flag=0;
        for(int j=0;j<m;j++){
            if(b[i]!=1&&c[j]!=1){
                printf("%c",a[i][j]);
            }
            if(b[i]==1){
                flag=1;
            }

            if(flag==0&&j==m-1)
             printf("\n");
        }
    }


    return 0;
}
