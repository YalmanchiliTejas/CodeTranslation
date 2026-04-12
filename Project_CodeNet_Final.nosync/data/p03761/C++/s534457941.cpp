#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
int ans[200];
int cnt[200];
char an[200];
int minn(int a,int b){
    return a<b? a:b;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(int i=0;i<200;i++) ans[i]=100100;
        for(int i=1;i<=n;i++){
            memset(cnt,0,sizeof(cnt));
            scanf("%s",an);
            for(int j=0;j<strlen(an);j++){
                cnt[an[j]]++;
            }
            for(int j=0;j<200;j++){
                ans[j]=minn(ans[j],cnt[j]);
            }
        }

        for(int i=97;i<97+26;i++){
            while(ans[i]){
                printf("%c",i);
                ans[i]--;
            }
        }
        printf("\n");
    }
    return 0;
}
