#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
typedef long double ld ;
const int N = 101;
ll dp[N][11][4][2];
int n,k;
int s[N];
ll go(int idx, int num,int cnt, int fl){
    if(idx==n-1){
        if(cnt==k)return 1;
        else return 0;
    }
    ll &ret = dp[idx][num][cnt][fl];
    if(ret!=-1)return ret;
    ret = 0;
    for(int i=0;i<=9;i++){
        if(fl){
            int zr = 0;
            if(i>0)zr = 1;
            if(cnt+zr>k)break;
            ret+=go(idx+1,i,cnt+zr,fl);
        }
        else{
            int zr = 0;
            if(i>0)zr = 1;
            int bg = 0;
            if(i<s[idx+1])bg = 1;
            if(i>s[idx+1])break;
            if(cnt+zr>k)break;
            ret+=go(idx+1,i,cnt+zr,bg);
        }
    }
    return ret;
}
void solve(){
    memset(dp,-1,sizeof dp);
    string ss;
    cin>>ss;
    n = ss.size();
    for(int i=0;i<n;i++)s[i] = ss[i]-'0';
    cin>>k;
    ll ans = 0;
    for(int i=0;i<=s[0];i++){
        ans+=go(0,i,int(i>0),int(i<s[0]));
    }
    cout<<ans<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)solve();
	return 0;
}
