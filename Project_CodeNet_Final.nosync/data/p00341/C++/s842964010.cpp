#include <stdio.h>
int size[3],a[12],s[3];
bool dfs(int now){
    if(now>=12)return true;
    else{
        for(int i=0;i<3;i++)if(s[i]==-1){
            size[i]=1;
            s[i]=a[now];
            if(dfs(now+1))return true;
            s[i]=-1;
            size[i]=0;
        }
        else if(s[i]==a[now]&&size[i]<5){
            size[i]++;
            if(dfs(now+1))return true;
            size[i]--;
        }
        return false;
    }
}
int main(){
    for(int i=0;i<3;i++)s[i]=-1;
    for(int i=0;i<12;i++)scanf("%d",&a[i]);
    if(dfs(0))printf("yes\n");
    else printf("no\n");
}
