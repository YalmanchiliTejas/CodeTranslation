#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define inf1 INT_MAX
#define inf2 LLONG_MAX
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define sbit __builtin_popcount
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define rit(it,x) for(auto it=x.begin();it!=x.end();it++)
#define cases(t) int t; cin>>t; rep(casn,1,t+1)
#define fill(a,b) memset(a,b,sizeof(a))
#define dbg(x) cerr<<#x<<" "<<x<<endl;
#define dbga(arr,n) cerr<<#arr<<": "; rep(tt,0,n)cerr<<arr[tt]<<" "; cerr<<endl;
#define infile ifstream fin; fin.open("input.txt")
#define outfile ofstream fout; fout.open("output.txt")
#define vec vector<int>
#define pii pair<int,int>
#define plii pair<ll,int>
#define pll pair<ll,ll>
#define p_queue priority_queue< plii,vector< plii >,greater< plii > > 
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
#define sp(x) setprecision(x)
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sl(x) scanf("%lld",&x)
#define sst(x) scanf("%s",x)
#define pl(x) printf("%lld\n",x)
#define pi(x) printf("%d\n",x)
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bs binary_search
ll dp[105][10005][2];
string s; int d;

inline ll binex(ll a,ll b)
{
    ll ans=1,temp=a%mod;
    while(b!=0){
        if(b&1) ans=(ans*temp)%mod;
        temp=(temp*temp)%mod;
        b=b>>1;
    }
    return ans;
}

inline ll solve(int idx,int mod1,int flag)
{
    if(dp[mod1][idx][flag]!=-1) return dp[mod1][idx][flag];
    if(idx==sz(s)){
        if(mod1==0) return 1;
        else return 0;
    }
    ll temp=0;
    if(flag==1){
        rep(i,0,s[idx]-'0') temp+=solve(idx+1,(((mod1-i+5*d)%d)+d)%d,0);
        temp+=solve(idx+1,(((mod1-(s[idx]-'0')+d)%d)+d)%d,1);
    }
    
    else{
        rep(i,0,10) temp+=solve(idx+1,(((mod1-i+d)%d)+d)%d,0);
    }
        //cerr<<idx<<" "<<mod1<<" "<<flag<<" "<<temp<<endl;
    return dp[mod1][idx][flag]=temp%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>s>>d;
    fill(dp,-1); cout<<(solve(0,0,1)-1+mod)%mod<<endl;
}