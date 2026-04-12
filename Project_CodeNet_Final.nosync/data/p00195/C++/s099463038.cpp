#include<cstdio>
using namespace std;
int main(){
    int x,y;
    while(scanf("%d%d",&x,&y),x,y){
        int data=0;
        int q = 0;
        data = x+y;
        for(int i = 1;i <= 4; i++){
            scanf("%d%d",&x,&y);
            if(data < x+y){
                data = x+y;
                q = i;
            }
        }
        printf("%c %d\n",q+65,data);
    }
    return 0;
}