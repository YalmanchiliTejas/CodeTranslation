#include<cstdio>
 using namespace std;
typedef struct{
    char name[30];
    int ten;
}team;
 
int main(){
    int n,i,j,k,m,h,f;
    team soccer[10],t;
    f=1;
    while(~scanf("%d",&m)){
        if(m==0)break;
        if(f!=1)printf("\n");
        f=2;
        for(i=0;i<m;i++){
            scanf(" %s %d %d %d ",soccer[i].name,&k,&n,&h);
            soccer[i].ten=3*k+h;
        }
         
        for(i=0;i<m;i++){
            for(j=0;j<m-1;j++){
                if(soccer[j].ten<soccer[j+1].ten){
                    t=soccer[j];
                    soccer[j]=soccer[j+1];
                    soccer[j+1]=t;
                }
            }
        }
        for(i=0;i<m;i++){
            printf("%s,%d\n",soccer[i].name,soccer[i].ten);
        }
    }
    return 0;
}