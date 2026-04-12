#include <stdio.h>
#include <algorithm>
using namespace std;
int x[10][10];
int gen(int g[],int s,int n,int c[]){

}
main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        x[a][b]=1;
        x[b][a]=1;
    }
    int co=0;
    do{
        int b=1;
        for(int i=0;i<n-1;i++){
            if(x[arr[i]][arr[i+1]]==0){
                b=0;
            }
        }
        co+=b;
    }while(next_permutation(arr+1,arr+n));
    printf("%d",co);
}
