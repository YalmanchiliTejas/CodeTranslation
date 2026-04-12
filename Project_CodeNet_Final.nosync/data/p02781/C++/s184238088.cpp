#include<bits/stdc++.h>
#define int long long int
#define inf 1000000000000
#define hell (int)(1e9+7)

using namespace std;

int dp[1000][4][2];

int helper(int st,string &s,bool flag,int k){
    if(k<0)
        return 0;
    if(st>=s.length())
        return k==0;
    if(dp[st][k][flag]!=-1)
        return dp[st][k][flag];
    int p;
    if(flag||st==0)
        p=s[st]-'0';
    else
        p=9;
    int ans=0;
    for(int i=0;i<=p;i++){
        if(st==0&&i==(s[st]-'0')){
            if(i!=0)
                ans+=helper(st+1,s,true,k-1);
            else
                ans+=helper(st+1,s,true,k);
        }
        else{
            if(i<(s[st]-'0')){
                if(i!=0)
                    ans+=helper(st+1,s,false,k-1);
                else
                    ans+=helper(st+1,s,false,k);
            }
            else{
                if(i!=0)
                    ans+=helper(st+1,s,flag,k-1);
                else
                    ans+=helper(st+1,s,flag,k);
            }
        }
    }
    return dp[st][k][flag]=ans;
}

void solve(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    memset(dp,-1,sizeof dp);
    int ans;
    ans=helper(0,s,false,k);
    cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	//cin>>t;
	t=1;
	while(t--){
		solve();
	}
	return 0;
}
