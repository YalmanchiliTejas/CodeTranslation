#include<bits/stdc++.h>
using namespace std;

int count(int **lines,int place,int depth){
    //lines: lines in the graph 
    //place: number that searching now
    int N=lines[0][0];
    int uplines[N+1][N+1];
    int *tmp[N+1];
    int sum=0;
    if(depth==N) return 1;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++)
            uplines[i][j]=lines[i][j];
        uplines[i][place]=0;
        tmp[i]=uplines[i];
    }
    for(int i=1;i<=N;i++)
        if(uplines[place][i]==1) sum+=count(tmp,i,depth+1);
    return sum;
}

int main(){
    int N,M;
    //data input
    cin>>N;
    cin>>M;
    int a[M],b[M];
    int lines[N+1][N+1];
    int *tmp[N+1];
    for(int i=0;i<M;i++){
        cin>>a[i];
        cin>>b[i];
    }

    //initialize
    for(int i=0;i<=N;i++){
        for(int j=1;j<=N;j++)
            lines[i][j]=0;        
        tmp[i]=lines[i];
    }
    lines[0][0]=N;

    //classification
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            if(a[j]==i)lines[i][b[j]]=1;
            if(b[j]==i)lines[i][a[j]]=1;
        }
    }
    cout<<count(tmp,1,1)<<endl;
    return 0;
}