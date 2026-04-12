#include <stdio.h>
int main(void){
    int n;
    scanf("%d",&n);
    int h[n];
    for(int i=0;i<n;i++){
        scanf("%d",h+i);
    }
    int ans=0;
    int z;
    for(int i=0;i<n;i++){
        z=1;
        for(int j=0;j<i;j++){
            if(h[j]>h[i])z=0;
        }
        ans+=z;
    }
    printf("%d\n",ans);
}