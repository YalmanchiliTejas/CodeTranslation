#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;

const ll m=1000000007;
int n;
ll x;
ll k[51];
ll ans;

ll dfs(int n,ll x){
    if(n==0)return 1;
    else if(x<=1) return 0;
    else if(1<x&&x-1<=k[n-1]) return dfs(n-1,x-1);
    else if(k[n-1]+2==x) return dfs(n-1,k[n-1])+1;
    else if(k[n-1]+2<x&&x<=k[n-1]*2+2) return dfs(n-1,k[n-1])+1+dfs(n-1,x-k[n-1]-2);
    else return dfs(n-1,k[n-1])*2+1;
}

int main(){
    
    cin>>n>>x;
    
    k[0]=1;
    for(int i=0;i+1<51;i++){
        k[i+1]=k[i]*2+3;
    }
    ans=dfs(n,x);
    cout<<ans<<endl;
    return 0;
}


