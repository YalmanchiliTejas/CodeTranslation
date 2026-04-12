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


//rec(L,R) will return the value of (x-y) for range [L,R]
long long rec(int L, int R){

    if(vis[L][R]==true)return dp[L][R];

    if(L==R)return vec[L];  //base case
    //if the current player removes the first element of the range
    long long score1 = vec[L] - rec(L+1,R);
    //if the current player removes the last element of the range
    long long score2 = vec[R] -  rec(L,R-1);

    vis[L][R]=true; //done for this range
    return dp[L][R] = max(score1,score2);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(vis,false,sizeof vis);
    cin>>n;

    input();

    //rec(0, n-1) will return the answer for range [0,n-1]
    //(x-y) where x is the score of first player , y is for second player
    cout<<rec(0,n-1)<<"\n";
}
