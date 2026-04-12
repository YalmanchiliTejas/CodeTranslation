#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n||m){
        int mav=0,mac=n+m;
        for(int i=1;i<5;i++){
            scanf("%d%d",&n,&m);
            if(n+m>mac){
                mac=n+m;
                mav=i;
            }
        }
        printf("%c %d\n",'A'+mav,mac);
    }

    return 0;
}