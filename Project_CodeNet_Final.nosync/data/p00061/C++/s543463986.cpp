#include<cstdio>
#include<iostream>
#include<map>
using namespace std;
int main(){
    int best[40]={0};
    bool flg[40]={0};
    map<int,int> m;
    int x,y;
    while(1){
        scanf("%d,%d",&x,&y);
        if(x==0&&y==0)break;
        m[x]=y;
        flg[y]=1;
    }
    int out=1;
    for(int i=30;i>=0;i--){
        if(flg[i]){
            best[i]=out;
            out++;
        }
    }
    while(cin>>x){
        cout<<best[m[x]]<<endl;
    }
    return 0;
}