#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int lim = 3e3+7;
const int inf = 1e9+9;

ll dp[lim][lim][2];
vector<int> a;

ll solve(int i, int j, int t){

    if(i>j) return 0;

    if(dp[i][j][t]!=-1) return dp[i][j][t];
    if(t){
        dp[i][j][1] = max(a[i]+solve(i+1,j,0), a[j]+solve(i,j-1,0));
    }
    else{
        dp[i][j][0] = min(-a[i]+solve(i+1,j,1), -a[j]+solve(i,j-1,1));
    }
    return dp[i][j][t];
}


void init(){
    for(int i=0;i<lim;i++){
        for(int j=0;j<lim;j++){
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
}


int main(){
    init();
    int n;
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(0,n-1,1);
    return 0;
}
