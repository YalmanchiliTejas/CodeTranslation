#include<stdio.h>

int main(){
        int i = 0,j = 0;
        int n = 1;
        int s[1000];
        int sum = 0;
        int tmp;
        while(1){
                scanf("%d",&n);
                if(n == 0)
                        break;               
                for(j=0;j<n;j++){
                        scanf("%d",&s[j]);
                }
                
                for(i = 0;i < n;i++){
                        for(j = n - 1; j > i; j--){
                                if(s[i] > s[j]){
                                        tmp = s[i];
                                        s[i] = s[j];
                                        s[j] = tmp;
                                }
                        }
                }
                for(j = 1;j < n - 1;j++){
                        sum += s[j];
                }
                printf("%d\n",sum/(n-2));                
                sum = 0;
        }        
        return 0;
}