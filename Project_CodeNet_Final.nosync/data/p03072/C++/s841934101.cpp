#include <cstdio>

int main (){
    int N;
    scanf("%d",&N);
    int height[N];
    for (int i = 0; i < N; i++){
        scanf("%d",&height[i]);
    }
    int count=1;
    int idx=0;
    for (int i = 1; i < N; i++){
        if(height[i]>=height[idx]){
            count++;
            idx=i;
        }
    }
    printf("%d",count);
}