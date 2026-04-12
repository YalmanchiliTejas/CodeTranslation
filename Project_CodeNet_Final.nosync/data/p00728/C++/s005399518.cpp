
#include <cstdio>

int main(){
   int n;

   while(true){
        scanf("%d",&n);
        if(n == 0){
            break;
        }
        int min = 1000;
        int max = 0;
        int sum = 0;
        for(int i = 0;i < n;i++){
            int k;
            scanf("%d",&k);
            if(k <= min){
                min = k;
            }
            if(k >= max){
                max = k;
            }
            sum += k;
        }
        printf("%d\n",(sum - (max + min)) / (n - 2));
    };
}
