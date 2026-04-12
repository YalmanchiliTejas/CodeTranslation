#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0);
const int M = 1e9+7;
using namespace std;
int d;
string k;
ll dp[10005][105][2];

int dfs(int pos, int r, int f){
    if(pos==k.size()){
        if(r==0)
            return 1;
        else
            return 0;
    }

    if(dp[pos][r][f]!=-1)
        return dp[pos][r][f];

    int LMT;
    if(f) // sequence till pos-1 is has a digit smaller
        LMT = 9;
    else
        LMT = k[pos]-'0';

    ll res = 0;
    for(int i=0; i<=LMT; i++){
        //cout<<"trying "<<i<<endl;
        int nf = f;
        if(f==0 && i<LMT) nf=1;
        res = (res+dfs(pos+1, (r+i)%d, nf))%M;
    }

    return dp[pos][r][f] = res%M;

}

int main(){
    AC
    memset(dp, -1, sizeof(dp));
    cin>>k>>d;
    cout<<(dfs(0,0,0)-1+M)%M<<endl;
}