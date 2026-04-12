#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
bool a[8][8];
int N;

int dfs(int u,bool check[]){
    bool all=true;
    for(int i=0;i<N;i++){
        if(check[i]==false) all=false;
    }
    if(all==true) return 1;
    int sum=0;
    for(int i=0;i<N;i++){
        if(a[u][i]==false) continue;
        if(check[i]==true) continue;
        check[i]=true;
        sum+=dfs(i,check);
        check[i]=false;
    }
    return sum;
}

int main(){
    int M;
    cin >> N >> M;
    memset(a,false,sizeof(a));
    for(int i=0;i<M;i++){
        int u,v;
        cin >> u >> v;
        a[u-1][v-1]=true;
        a[v-1][u-1]=true;
    }
    bool check[N];
    memset(check,false,sizeof(check));
    check[0]=true;
    cout << dfs(0,check) << endl;
    return 0;
}