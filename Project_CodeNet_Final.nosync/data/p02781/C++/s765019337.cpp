#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;
int main(){
    string n;
    int k,x;
    cin>>n>>k;
    ll dp[1000][2][4];
    dp[0][0][0]=1;
    rep(i,n.size())rep(j,2)rep(k,4){
        if(j==1) x=9;
        else x=n[i]-'0';
        rep(l,x+1) if(k+(l!=0)<4) dp[i+1][j||l<x][k+(l!=0)]+=dp[i][j][k];
    }
    cout<<dp[n.size()][0][k]+dp[n.size()][1][k]<<endl;
}