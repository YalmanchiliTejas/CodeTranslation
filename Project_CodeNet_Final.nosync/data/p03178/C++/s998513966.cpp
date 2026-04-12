#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
//int mod(int a,int b){int ret=a%b;if(ret<0)ret+=b;return ret;}
string n;
int k;
int dp[mxN][105][2];//position,sum,limit
int solve(int pos,int m,int e){
    m%=k;
    if(pos==sz(n)){
        if(m==0)return 1;
        return 0;
    }
    if(dp[pos][m][e]!=-1)return dp[pos][m][e];
    int ans=0;
    int lim=9;
    if(e==1)lim=(int)(n[pos]-'0');
    for(int i=0;i<=lim;i++){
        int ne=e;
        if(ne==1 && i<lim)ne=0;
        ans=(ans+solve(pos+1,(m+i)%k,ne))%M;
    }
    return dp[pos][m][e]=ans%M;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    int ans=(solve(0,0,1)-1)%M;
    cout << (ans < 0 ? ans+M:ans);
    
}