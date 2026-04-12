#include<bits/stdc++.h>
using namespace std;
int a[10][10],m,n,flag;//a数组表示能不能选
char kk[10];//这个数组用来输入
void dfs(int x,int y){
    if(x==m-1&&y==n-1){//如果能走到最后一格
        for(int i=0;i<m;++i)for(int j=0;j<n;++j){
            if(a[i][j])return;//如果有个没走过
        }
        flag=1;//标记
        return;//返回
    }
    if(flag==1)return;//加快，优化
    if(a[x+1][y]){//如果可以向下走
        a[x+1][y]=0;//表示走过
        dfs(x+1,y);
        a[x+1][y]=1;//回溯
    }
    if(a[x][y+1]){//同上（懒）
        a[x][y+1]=0;
        dfs(x,y+1);
        a[x][y+1]=1;
    }
    if(!a[x][y+1]&&!a[x+1][y])return;
    //如果既不能向右又不能向下，就返回
}
int main(){
    scanf("%d%d",&m,&n);
    for(int i=0;i<=m;++i){
        gets(kk);//输入
        for(int j=0;j<n;++j)
        if(kk[j]=='#')a[i-1][j]=1;
        //如果是#，就说明可以从这里走
    }
    if(a[0][0]){
        a[0][0]=0;//肯定要走，先打上标记
        dfs(0,0);
    }
    if(flag)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;
    return 0;
}