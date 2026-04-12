
#include <cstdio>

int main(){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    for(int i = 1;; i++){
        if(y * i + z * (i + 1) > x){
            printf("%d\n",i - 1);
            break;
        }
    }

    return 0;
}