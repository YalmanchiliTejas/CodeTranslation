#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m;
    scanf("%d",&m);
    while(m--){
        int g,y,n,ma=0;
        scanf("%d%d%d",&g,&y,&n);
        while(n--){
            int t,x;
            double r;
            scanf("%d%lf%d",&t,&r,&x);
            int z=g;
            if(!t){
                int b=0;
                for(int i=0;i<y;i++){
                    b+=(int)(z*r);
                    z-=x;
                }
                z+=b;
            }else{
                for(int i=0;i<y;i++)z=z+(int)(z*r)-x;
            }
            ma=max(ma,z);
        }
        printf("%d\n",ma);
    }
    return 0;
}