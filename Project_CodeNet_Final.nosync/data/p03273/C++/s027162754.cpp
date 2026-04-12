#include<cstdio>
char a[100][101];
bool wflag[100],hflag[100];
int main(){
    int h,w;
    scanf("%d%d",&h,&w);
    for(int i=0;i<h;i++)scanf("%s",a[i]);
    for(int i=0;i<h;i++){
        hflag[i]=true;
        for(int j=0;j<w;j++){
            if(a[i][j]=='#'){
                hflag[i]=false;
                break;
            }
        }
    }
    for(int i=0;i<w;i++){
        wflag[i]=true;
        for(int j=0;j<h;j++){
            if(a[j][i]=='#'){
                wflag[i]=false;
                break;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(!hflag[i]){
            for(int j=0;j<w;j++){
                if(!wflag[j]){
                    printf("%c",a[i][j]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}