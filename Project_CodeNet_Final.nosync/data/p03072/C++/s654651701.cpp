#include<stdio.h>
#include<math.h>

int main(){
    int n,max = 0,count = 1;
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++){
        scanf("%d",&a[i]);
    }
    max = a[0];
    for(int i = 1;i < n;i++){
        if(max <= a[i]){
            count++;
            max = a[i];
        }
    }
    printf("%d\n",count);
}