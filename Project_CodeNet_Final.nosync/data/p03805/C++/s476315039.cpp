#include<iostream>
using namespace std;

static const int MAX=10;

int n,m;
int d[MAX]={}; //チェックカウンタ
int R[MAX][MAX]={}; //隣接行列
bool all_visit;

int dfs(int x){
    all_visit=true;
    for(int i=0;i<n;i++){
        if(d[i]==0){
            all_visit=false;
        }
    }

    if(all_visit) return 1;

    int ans=0;

    for(int i=0;i<n;i++){
        if(d[i]==0&&R[x][i]!=0){
            d[i]=1;
            ans+=dfs(i);
            d[i]=0;
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        R[a][b]++;
        R[b][a]++;
    }
    d[0]=1;
    cout << dfs(0) << endl;
}