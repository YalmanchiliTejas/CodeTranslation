#include<stdio.h>
#include<string.h>
#include<math.h>
int as[104][104];
int main(){
    char s[103][104];
    int i,j,r,c,cnt;
    scanf("%d%d",&r,&c);
    for(i=0;i<r;i++){
        scanf("%s",s[i]);
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cnt=0;
            if(s[i][j]!='.') continue;
            for(int k=0;k<c-1;k++){
                if(s[i][k]==s[i][k+1]) cnt++;
                else break;
            }
            if(cnt==c-1) as[i][j]=1;
            cnt=0;
            for(int k=0;k<r-1;k++){
                if(s[k][j]==s[k+1][j])cnt++;
                else break;
            }
            if(cnt==r-1) as[i][j]=1;
        }
    }

    for(i=0;i<r;i++){
        int u=0;
        for(j=0;j<c;j++){
            if(!as[i][j]){
                 printf("%c",s[i][j]);
                 u=1;
            }
        }
        if(u) printf("\n");
    }


}
