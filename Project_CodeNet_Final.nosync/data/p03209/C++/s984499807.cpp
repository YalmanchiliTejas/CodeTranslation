#include<bits/stdc++.h>

using namespace std;

vector<long long > baga,pate;

long long dfs(int size,long long num){
    long long ans=0;
    if(num<=0){
        return ans;
    }

    if(baga[size]<=num){
        return pate[size];
    }

    ans +=dfs(size -1,min(num,baga[size]/2+1)-1);
    if(num>baga[size]/2){
        ans+=1;
        ans+=dfs(size-1,num-(baga[size]/2)-1);
    }

    return ans;

}


int main(){
    long long  N,X;
    cin>>N>>X;

    baga.assign(N+1, 0), pate.assign(N+1, 0);
    baga[0] = 1;
    pate[0] = 1;

    for(int i=0;i<N;++i){
        baga[i+1]=baga[i]*2+3;
        pate[i+1]=pate[i]*2+1;
    }

    cout<<dfs(N,X)<<endl;

}