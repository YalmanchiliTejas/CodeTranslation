#include<iostream>
#include<string>
#include<stdio.h>
#include<cstdio>
#include<math.h>
using namespace std;
int main(){
    int a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,max=-10000;
    int sum[100];
    char ch;
    while(1){
        cin>>a1>>a2;
        if(a1==0 && a2==0){
            break;
        }
        cin>>b1>>b2>>c1>>c2>>d1>>d2>>e1>>e2;
        sum[0]=a1+a2;sum[1]=b1+b2;sum[2]=c1+c2;sum[3]=d1+d2;sum[4]=e1+e2;
        for(int i=0;i<5;i++){
            if(sum[i]>max){
                   max=sum[i];
                ch='A'+i;
            }
        }
        cout<<ch<<" "<<max<<endl;
        max=-10000;
    }
    return 0;
}