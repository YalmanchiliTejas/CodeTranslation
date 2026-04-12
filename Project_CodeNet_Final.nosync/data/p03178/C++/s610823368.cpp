#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string s;
int d,dp[10005][101][2];
int sol(int pos,int sum,int f){
    if(pos==sz(s)) return sum==0;
    int &ans=dp[pos][sum][f];
    if(ans!=-1) return ans;
    ans=0;
    rep(i,0,10){
        if(f){
            ans=(ans+sol(pos+1,(sum+i)%d,f))%hell;
        }
        else{
            if(i<s[pos]-'0'){
                ans=(ans+sol(pos+1,(sum+i)%d,1))%hell;   
            }
            else if(i==s[pos]-'0'){
                ans=(ans+sol(pos+1,(sum+i)%d,0))%hell;
            }
            else break;
        }
    }
    return ans;
}
void solve(){
    cin>>s>>d;
    memset(dp,-1,sizeof dp);
    cout<<(sol(0,0,0)-1+hell)%hell<<endl; 
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}