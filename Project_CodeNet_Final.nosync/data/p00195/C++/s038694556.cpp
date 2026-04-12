#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){
    int n,sum[5]={0},am,pm,i=0,max=-1000,num;
    bool bo=false;
    char ans;
    while(1){
        for(i=0;i<5;i++){
            cin>>am>>pm;
            if(am==0 && pm==0){
                bo=true;
                break;
            }
            sum[i]=am+pm;
        }
        if(bo){
            break;
        }
        for(int i=0;i<5;i++){
            if(sum[i]>max){
                max=sum[i];
                num=i;
            }
        }
        ans='A'+num;
        cout<<ans<<" "<<max<<endl;
        max=-1000;
    }
    return 0;
}