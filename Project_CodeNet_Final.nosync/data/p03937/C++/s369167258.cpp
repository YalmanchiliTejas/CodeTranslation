#include <iostream>

using namespace std;
int xx[]={-1,0,1,0};
int yy[]={0,-1,0,1},n,m;
int b=0;
    char mat[1000][1000];
void dfs(int y,int x){
    b++;
    if(y<0||y>=n||x<0||x>=m)return;
    mat[y][x]='.';
    int c=0,aux1,aux2,c2=0;
    for(int i=0;i<4;i++){
        if(mat[y+yy[i]][x+xx[i]]=='#'){
            c++;
            if(i<2)c2++;
            aux1=y+yy[i];
            aux2=x+xx[i];
        }
    }
    if(c==1&&c2==1)dfs(aux1,aux2);
    return;
}
int main()
{
    int x=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]=='#')x++;
        }
    }
    dfs(n-1,m-1);
    if(b==x)cout<<"Possible";
    else cout<<"Impossible";
    return 0;
}
