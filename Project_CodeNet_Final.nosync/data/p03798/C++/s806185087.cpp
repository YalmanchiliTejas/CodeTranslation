#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll ;

bool check(vector<int> &A,vector<int> &ans,int N,int n,int m){
    ans[0]=n;ans[1]=m;
    for(int i=1;i<N-1;i++){
        ans[i+1]=A[i]*ans[i]*ans[i-1];
    }
    int tp=A[N-1]*ans[N-1]*ans[N-2];
    int ty=A[0]*ans[0]*ans[1];
    if(tp==ans[0]&&ty==ans[N-1])return true;
    else return false;
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        char c;
        cin>> c;
        if(c=='x')A[i]=-1;
        else A[i]=1;
    }
    vector<int> ans(N);
    if(check(A,ans,N,1,1)){
        for(int i=0;i<N;i++){
            if(ans[i]==1)cout<<'S';
            else cout<<'W';
        }
        return 0;
    }if(check(A,ans,N,1,-1)){
        for(int i=0;i<N;i++){
            if(ans[i]==1)cout<<'S';
            else cout<<'W';
        }
        return 0;
    }if(check(A,ans,N,-1,1)){
        for(int i=0;i<N;i++){
            if(ans[i]==1)cout<<'S';
            else cout<<'W';
        }
        return 0;
    }if(check(A,ans,N,-1,-1)){
        for(int i=0;i<N;i++){
            if(ans[i]==1)cout<<'S';
            else cout<<'W';
        }
        return 0;
    }
    cout<<-1;
    return 0;
}