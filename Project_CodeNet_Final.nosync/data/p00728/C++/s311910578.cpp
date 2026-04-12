#include <stdio.h>
#include <stdlib.h>

int main(){
    
    // 各種変数宣言
    
    int n,x,y,i,j,k,c,a,p=0;
    int min,max,answer,carda[100];
    // 配列宣言
    
    
    // メインループ
    
    while(1){
        int card[500]={};
        
        // nとpを読み込む
        scanf("%d", &n);
        if(n==0)break;
        
        for(i=0;i<n;i++){
        scanf("%d", &card[i]);
        }
        
        min=1001;
        for(i=0;i<n;i++){
            if(min>card[i] || min==card[i]){
                min=card[i];
                x=i;
            }
        }
        
        max=0;
        for(i=0;i<n;i++){
            if(max<card[i] || max==card[i]){
                max=card[i];
                y=i;
            }
        }
        
        
        card[x]=0;
        card[y]=0;
        k=0;
        for(i=0;i<n;i++){
            k+=card[i];
        }
        
        answer=k/(n-2);
        carda[p]=answer;
        p++;
    }
    for(i=0;i<p;i++){
        printf("%d\n",carda[i]);
    }
    // 終了
    return 0;
    
}

