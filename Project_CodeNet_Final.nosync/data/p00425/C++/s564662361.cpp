#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    int xi[6]={1,2,3,4,5,6};
    int sum;
    char nowcomand[6],comand[6][6]={{"North"},{"East"},{"West"},{"South"},{"Right"},{"Left"}};
    while(1){
        scanf("%d",&n);
        if(n==0)
            break;
        sum=0;
        for(int i=0;i<6;i++)
            xi[i]=i+1;
        for(int i=0;i<n;i++){
            scanf("%s",nowcomand);
            if(!strcmp(nowcomand,comand[0]))
                swap(xi[0],xi[1]),swap(xi[1],xi[5]),swap(xi[5],xi[4]);
            else if(!strcmp(nowcomand,comand[1]))
                swap(xi[0],xi[3]),swap(xi[3],xi[5]),swap(xi[5],xi[2]);
            else if(!strcmp(nowcomand,comand[2]))
                swap(xi[0],xi[2]),swap(xi[2],xi[5]),swap(xi[5],xi[3]);
            else if(!strcmp(nowcomand,comand[3]))
                swap(xi[0],xi[4]),swap(xi[4],xi[5]),swap(xi[5],xi[1]);
            else if(!strcmp(nowcomand,comand[4]))
                swap(xi[1],xi[2]),swap(xi[2],xi[4]),swap(xi[4],xi[3]);
            else
                swap(xi[1],xi[3]),swap(xi[3],xi[4]),swap(xi[4],xi[2]);
            sum+=xi[0];
        }
        printf("%d\n",sum+1);
    }
    return 0;
}