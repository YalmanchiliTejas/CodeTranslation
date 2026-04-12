#include<cstdio>
int main(){
    int n,h[20]={},ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&h[i]);
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<i;j++){
            if(h[j]>h[i])flag=false;
        }
        if(flag)ans++;
    }
    printf("%d\n",ans);
    return 0;
}