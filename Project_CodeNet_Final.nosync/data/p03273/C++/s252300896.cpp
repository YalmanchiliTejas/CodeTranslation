#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m,x[maxn][maxn];
inline bool checkh(int h){
    for(register int j=1;j<=m;j++) if(x[h][j]) return false;
    return true;
}
inline bool checkl(int l){
    for(register int i=1;i<=n;i++) if(x[i][l]) return false;
    return true;
}
int main(){
    scanf("%d%d",&n,&m);char ch;
    for(register int i=1;i<=n;i++){
        getchar();
        for(register int j=1;j<=m;j++){
            ch=getchar();
            if(ch=='#') x[i][j]=1;
        }
    }
    for(register int i=1;i<=n;i++) if(checkh(i)){
        for(register int p=i;p<n;p++){
            for(register int q=1;q<=m;q++) x[p][q]=x[p+1][q];
        }
        n--;i--;
    }
    for(register int j=1;j<=m;j++) if(checkl(j)){
        for(register int q=j;q<m;q++){
            for(register int p=1;p<=n;p++) x[p][q]=x[p][q+1];
        }
        m--;j--;
    }
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=m;j++) putchar(x[i][j]?'#':'.');
        putchar('\n');
    }
    return 0;
}