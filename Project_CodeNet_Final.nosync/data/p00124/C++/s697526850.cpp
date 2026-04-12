#include <stdio.h>
#include <iostream>
using namespace std;
const int N=1e2+10;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
    return ;
}
int main(){
    int n,f[N],a[N],w,l,d;
    bool first=true;
    string c[N];
    while(true){
        scanf("%d",&n);
        if(n==0)return 0;
        if(first)first=false;
        else printf("\n");
        for(int i=0;i<n;i++){
            cin>>c[i];
            f[i]=i;
            scanf("%d%d%d",&w,&l,&d);
            a[i]=w*3+d;
        }
        for(int i=0;i<n;i++)for(int j=1;j<n;j++)if(a[f[j-1]]<a[f[j]])swap(f[j],f[j-1]);
        for(int i=0;i<n;i++)cout<<c[f[i]]<<","<<a[f[i]]<<endl;
    }
}
