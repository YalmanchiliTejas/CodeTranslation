#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<map>

using namespace std;

const int MAX_N=50;
long long layer[MAX_N+1];
long long numOfP[MAX_N+1];
long long numOfB[MAX_N+1];

long long solve(int M,long long x){//レベルMバーガーのx枚目までにあるパティの数
    if(M==1){
        if(x==1){
            return 0;
        }else if(x==2){
            return 1;
        }else if(x==3){
            return 2;
        }else{
            return 3;
        }
    }
    if(x==1){
        return 0;
    }else if(x == layer[M]){
        return numOfP[M];
    }else if(x == ((layer[M]+1)/2) ){
        return numOfP[M-1]+1;
    }else if(x >  ((layer[M]+1)/2) ){
        return (numOfP[M-1]+solve(M-1,x-layer[M-1]-2)+1);
    }else{
        return (solve(M-1,x-1));
    }
}

int main(){
    int N;
    long long X;
    cin>>N>>X;
    layer[0]=1;
    numOfP[0]=1;
    numOfB[0]=0;
    for(int i=1;i<=MAX_N;i++){
        layer[i]=layer[i-1]*2+3;
        numOfP[i]=2*numOfP[i-1]+1;
        numOfB[i]=2*numOfB[i-1]+2;
        //cout<<layer[i]<<' '<<numOfP[i]<<' '<<numOfB[i]<<endl;
    }
    cout<<solve(N,X)<<endl;
    return 0;
}
