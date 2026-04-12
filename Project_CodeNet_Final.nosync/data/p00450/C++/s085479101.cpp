#include<cstdio>
using namespace std;

int main(){
    int n;
    int wh[128]={0};
    int k=0;
    while(scanf("%d",&n),n){
        int c[150000]={0};
        for(int i=1;i<=n;i++){
            scanf("%d",&c[i]);
            c[0]=c[i];
            if(i%2==0){
                int j=i-1;
                if(c[i]!=c[i-1] && c[i]==1){
                    for(;;){
                        if(c[i]==c[j])break;
                        c[j]=1;
                        j--;
                    }
                }else if(c[i]!=c[i-1] && c[i]==0){
                    for(;;){
                        if(c[i]==c[j])break;
                        c[j]=0;
                        j--;
                    }
                }
            }
        }
        int cnt[128]={0};

        for(int i=1;i<=n;i++){
            if(c[i]==0)cnt[k]++;
            wh[k]=cnt[k];
        }
        wh[k]=cnt[k];
        k++;
    }
    for(int i=0;i<k;i++){
        printf("%d\n",wh[i]);
    }
    return 0;
}