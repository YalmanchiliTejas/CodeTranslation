#include <iostream>
int main(void){

    int n, data[20], i, cnt, max;
    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &data[i]);
    }

    max=data[0];
    cnt=1;
    for(i=1;i<n;i++){
        if(data[i]>=max){
            max=data[i];
            cnt++;
        }
    }

    printf("%d\n", cnt);

    return 0;
}