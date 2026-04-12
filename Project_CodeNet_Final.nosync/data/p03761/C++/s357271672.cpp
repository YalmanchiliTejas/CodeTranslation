#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[200],ans[200];
char b[200];
int main(){
    int n;
    while(~scanf("%d",&n)){
        int p=0;
        while(p++<n){
            scanf("%s",b);
            //printf("%d\n",p);
            int len=strlen(b);
            memset(a,0,sizeof(a));
            for(int i=0;i<len;i++){
                a[b[i]]++;
            }
            //printf("%d %d\n",a['a'],'a');
            if(p==1){
                for(int i=0;i<200;i++){
                    ans[i]=a[i];
                }
            }
            else{
                for(int i=0;i<200;i++){
                    if(a[i]<ans[i]){
                        ans[i]=a[i];
                    }
                }
            }
        }
        for(int i=0;i<200;i++){

            if(ans[i]>0){

                for(int j=0;j<ans[i];j++){
                    printf("%c",i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
