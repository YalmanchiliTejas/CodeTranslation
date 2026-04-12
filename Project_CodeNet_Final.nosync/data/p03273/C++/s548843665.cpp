#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long int
using namespace std;
int n,m,x[105],y[105];
char a[105][105];
char c;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           cin>>a[i][j];
           if(a[i][j]=='#'){
               x[i]=1;
               y[j]=1;
           }
        }
    }
    for(int i=1;i<=n;i++){
        int pd=1;
        for(int j=1;j<=m;j++){
            if(x[i]&&y[j]){
                printf("%c",a[i][j]);
                pd=0;
            }
        }
        if(pd==0)
        printf("\n");
    }
    return 0;
}