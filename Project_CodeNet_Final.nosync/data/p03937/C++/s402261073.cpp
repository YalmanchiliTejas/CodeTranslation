#include<cstdio>
int main(){
    int h,w;
    char a[8][9];
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++)scanf("%s",a[i]);
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'&&(i!=h-1||j!=w-1)){
                int d=0;
                if(a[i][j+1]=='#')d++;
                if(i+1<h&&a[i+1][j]=='#')d++;
                if(d!=1){
                    printf("Impossible");
                    return 0;
                }
            }
            if(a[i][j]=='#'&&(i!=0||j!=0)){
                int d=0;
                if(j>0&&a[i][j-1]=='#')d++;
                if(i>0&&a[i-1][j]=='#')d++;
                if(d!=1){
                    printf("Impossible");
                    return 0;
                }
            }
        }
    }
    printf("Possible");
    return 0;
}