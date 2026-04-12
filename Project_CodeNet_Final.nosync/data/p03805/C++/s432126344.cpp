#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
#define inf 99999999
using namespace std;
const int MAX=100+10;
int map[MAX][MAX],n,m,result=0,book[MAX][MAX],bookt[MAX];
void path(int s,int sum){
    if(sum==n){
        result++;return;
    }
    for(int i=1;i<=n;i++){
        if(bookt[i]==0&&book[s][i]==0&&map[s][i]==1){
            //cout<<s<<"&"<<i<<"*"<<book[s][i]<<endl;
            bookt[i]=1;
            book[i][s]=book[s][i]=1;
            path(i,sum+1);
            book[i][s]=book[s][i]=0;
            bookt[i]=0;
        }
    }
}
int main(){
    #ifdef SIYU
    freopen("in.txt","r",stdin);
    #endif // SIYU
    int i,j,a,b;
    memset(map,0,sizeof(map));
    memset(book,0,sizeof(book));
    memset(bookt,0,sizeof(bookt));
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d%d",&a,&b);
        map[a][b]=map[b][a]=1;
    }
    bookt[1]=1;
    path(1,1);
    cout<<result<<endl;
    return 0;
}
