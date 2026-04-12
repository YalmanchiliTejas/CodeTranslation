#include<stdio.h>

int main(void){
    int N = 0;
    scanf("%d\n", &N);
    int H[20];
    for(int i = 0; i < N; i++){
        scanf("%d", &H[i]);
    }

    int cnt = 1;
    for(int i = 1; i < N; i++){ //基準値が配列０番目位に入るため、１から開始
        int clear = 0;
        for(int j = 0; j < i; j++ ){ // 全探索
            if(H[j] <= H[i]){
                clear++;
            }
        }
        if(clear == i){
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}