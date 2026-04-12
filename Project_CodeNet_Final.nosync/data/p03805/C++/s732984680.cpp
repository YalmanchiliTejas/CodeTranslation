#include <iostream>
#include <stack>
using namespace std;

int cnt;
void chk(bool map[9][9], int N, int cur, int depth, bool checked[9]){
    if(depth==N){
        cnt++;
        return;
    }
    for(int i=1;i<=N;i++){
        if(map[cur][i]&&(!checked[i])){
            bool fl[9];
            for(int j=1;j<=8;j++) fl[j]=checked[j];
            fl[i]=true;
            chk(map,N,i,depth+1,fl);
        }
    }
}

int main(){
    int M,N;
    cin >> N >> M;

    bool map[9][9];
    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++){
            map[i][j]=false;
        }
    }

    for(int i=0;i<M;i++){
        int a,b;
        cin >> a >> b;
        map[a][b]=true;
        map[b][a]=true;
    }

    bool fl[9];
    for(int i=1;i<=8;i++) fl[i]=false;

    cnt=0;
    fl[1]=true;
    chk(map,N,1,1,fl);

    cout << cnt << endl;

    return 0;
}