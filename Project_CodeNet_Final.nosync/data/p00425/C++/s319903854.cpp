#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    int n,to[128]={1};
    int di[8]={0,1,6,2,3,5,4};
    string mo;
    int cnt=0;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            cin>>mo;
            if(mo=="North"){
                di[0]=di[1];
                di[1]=di[3];
                di[3]=di[2];
                di[2]=di[5];
                di[5]=di[0];
                to[cnt]+=di[1];
            }else if(mo=="East"){
                di[0]=di[1];
                di[1]=di[6];
                di[6]=di[2];
                di[2]=di[4];
                di[4]=di[0];
                to[cnt]+=di[1];
            }else if(mo=="West"){
                di[0]=di[1];
                di[1]=di[4];
                di[4]=di[2];
                di[2]=di[6];
                di[6]=di[0];
                to[cnt]+=di[1];
            }else if(mo=="South"){
                di[0]=di[1];
                di[1]=di[5];
                di[5]=di[2];
                di[2]=di[3];
                di[3]=di[0];
                to[cnt]+=di[1];
            }else if(mo=="Right"){
                di[0]=di[3];
                di[3]=di[4];
                di[4]=di[5];
                di[5]=di[6];
                di[6]=di[0];
                to[cnt]+=di[1];
            }else if(mo=="Left"){
                di[0]=di[3];
                di[3]=di[6];
                di[6]=di[5];
                di[5]=di[4];
                di[4]=di[0];
                to[cnt]+=di[1];
            }
        }cnt++;
        to[cnt]=1;
        di[0]=0;
        di[1]=1;
        di[2]=6;
        di[3]=2;
        di[4]=3;
        di[5]=5;
        di[6]=4;
    }
    for(int i=0;i<cnt;i++){
        printf("%d\n",to[i]);
    }
    return 0;
}