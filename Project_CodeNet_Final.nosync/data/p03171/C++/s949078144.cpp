#include<bits/stdc++.h>

using namespace std;

int n;
vector<long long>vec;

void input(){
    for(int i=0;i<n;i++){
        long long a;
        cin>>a;

        vec.push_back(a);
    }
}

long long dp[3003][3003];
bool vis[3003][3003];
long long rec(int L, int R){

    if(vis[L][R]==true)return dp[L][R];

    if(L==R)return vec[L];

    long long a = vec[L] - rec(L+1,R);

    long long b = vec[R] -  rec(L,R-1);

    vis[L][R]=true;
    return dp[L][R] = max(a,b);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(vis,false,sizeof vis);

    cin>>n;

    input();

    cout<<rec(0,n-1)<<"\n";
}
