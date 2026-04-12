#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N,X,M;
    cin >> N >> X >> M;

    //ex
    if(N==1){
        cout << X << endl;
        system("pause");
        return 0;
    }


    long long visited[M];
    fill(visited,visited+M,-1);
    visited[X]=1;
    long long Y;
    long long fi,se;
    long long X_sub=X;
    while(1){
        Y=(X_sub*X_sub)%M;
        if(visited[Y]<0){
            visited[Y]=visited[X_sub]+1;
            X_sub=Y;
            if(visited[Y]==N){
                fi=1;
                se=N;
            }
        }else{
            fi=visited[Y];
            se=visited[X_sub];
            break;
        }
    }
    long long A[200000];
    long long i;
    A[1]=X;
    for(i=2; i<=se; i++){
        A[i]=(A[i-1]*A[i-1])%M;
    }
    long long ans=0;
    for(i=1; i<=fi-1; i++){
        ans+=A[i];
    }
    long long val=0;
    N-=(fi-1);
    for(i=fi; i<=se; i++){
        val+=A[i];
    }
    ans+=val*(N/(se-fi+1));
    N%=(se-fi+1);
    if(N>0){
        for(i=fi; i<=se; i++){
            ans+=A[i];
            N--;
            if(N==0) break;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}