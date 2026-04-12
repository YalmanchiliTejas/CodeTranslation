#include<bits/stdc++.h>
using namespace std;

int n,m;
int G[8][8];

int res(int cur,int dip,int a[8]){
    //cout<<cur<<endl;
    int sum=0;
    if(dip==n){
        return 1;
    }
    for(int i=0; i<8; i++){
        if(G[cur][i]&&!a[i]){
            int *used=new int[8];
            for(int i=0; i<8; i++){
                used[i]=a[i];
            }
            used[i]=1;
            //cout<<cur<<' '<<i<<endl;
            sum+=res(i,dip+1,used);
            delete[] used;
        }
    }
    return sum;
}

int main(){
    cin>>n>>m;
    int used[8];
    for(int i=0; i<8; i++){
        used[i]=0;
    }
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a][b]=1;
        G[b][a]=1;
    }
    used[0]=1;
    cout<<res(0,1,used)<<endl;
    return 0;
}

