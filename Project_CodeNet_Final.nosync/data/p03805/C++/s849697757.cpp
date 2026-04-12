#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;

int main(){
    int N,M;
    cin >> N >> M;
    bool a[N][N];
    memset(a,false,sizeof(a));
    for(int i=0;i<M;i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        a[x][y]=true;
        a[y][x]=true;
    }
    int v[N];
    for(int i=0;i<N;i++) v[i]=i;
    int ans=0;
    do{
        if(v[0]!=0) continue;
        for(int i=0;i<N-1;i++){
            if(a[v[i]][v[i+1]]==false) break;
            if(i==N-2) ans++;
        }
    }while(next_permutation(v,v+N));
    cout << ans << endl;
    return 0;
}