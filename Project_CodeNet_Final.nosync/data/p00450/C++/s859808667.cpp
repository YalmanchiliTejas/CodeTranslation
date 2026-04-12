#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0)
            break;
        int fie[100100]={0},che=0,bef,start,ans=0;
        for(int i=1;i<=n;i++){
            int now;
            scanf("%d",&now);
            if(i==1)
                start=now,fie[che]++,bef=now;
            else if(i%2==1){
                if(bef!=now)
                    che++;
                fie[che]++;
            }
            else{
                if(bef!=now&&che!=0)
                    fie[che-1]+=fie[che]+1,fie[che]=0,che--;
                else
                    fie[che]++;
                if(bef!=now&&che==0)
                    start=now;

            }
            //printf("[%d][%d]\n",start,che);
            bef=now;
        }
        /*
        for(int i=0;i<10;i++)
            printf("[%d]",fie[i]);
        puts("");
        */
        for(int i=start;fie[i]!=0;i+=2)
            ans+=fie[i];
        printf("%d\n",ans);
    }
    return 0;
}