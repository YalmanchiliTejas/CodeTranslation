#include<cstdio>

int main(){
    int n, h[105];
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d", &h[i]);
    }
    int c=1;
    for(int i=1;i<n;i++){
        bool b=true;
        for(int j=i;j>=0;j--){
            if(h[i]<h[j]){
                b=false;
            }
        }
        if(b)
            c++;
    }
    printf("%d", c);
    return 0;
}
