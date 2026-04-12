#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[10][10],n,ans=0;//10*10にしたのは番兵を含めたため
void move_tree(int now,int cnt,int *check_num){
    if(cnt==n-1){
        for(int i=0;num[now][i]!=0;i++){
            if(check_num[num[now][i]]==0)ans++;
        }
    }
    else{
        for(int i=0;num[now][i]!=0;i++){
            if(check_num[num[now][i]]==0){
                check_num[num[now][i]]=1;
                move_tree(num[now][i],cnt+1,check_num);
                check_num[num[now][i]]=0;
            }
        }
    }
}
int main(){
    int m,check[9]={0,1/*1は始点なので行った扱いにする*/,0,0,0,0,0,0,0},a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        int hoge=0;
        while(num[a][hoge]!=0)hoge++;
        num[a][hoge]=b;
        hoge=0;
        while(num[b][hoge]!=0)hoge++;
        num[b][hoge]=a;
    }
    move_tree(1,1,check);
    cout<<ans<<endl;

}