#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
template<class Read>void in(Read &x){
    x=0;
    int f=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        f|=(ch=='-');
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    x=f?-x:x;
    return;
}
int n,m,f[10005][4][2];
char ch[10005];
int dfs(int x,int y,int c){
    if(y>m)return 0;
    if(x>n)return y==m;
    if(f[x][y][c]!=-1)return f[x][y][c];
    int ok=c==1?ch[x]-'0':9;
    int sum=0;
    for(int i=0;i<=ok;i++)sum+=dfs(x+1,y+(i!=0),c&&i==ok);
    return f[x][y][c]=sum;
}
int main(){
    memset(f,-1,sizeof(f));
	scanf("%s",ch+1);
    in(m);
    n=strlen(ch+1);
    cout<<dfs(1,0,1)<<endl;
	return 0;
}
