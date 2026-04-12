#include <bits/stdc++.h>

using namespace std;
#define int long long int
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define vi vector <int>
#define sz(s) (int)s.size()
#define pii pair<int,int>
#define piii pair< int,pair<int,int> >
#define tiii tuple <int,int,int>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define rall(v) v.rbegin(),v.rend()
#define endl '\n'
#define matrix vector <vector <int> >
#define boost ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define NAYAN freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define N 10002
#define mod 1000000007
#define mod2 998244353
#define inf 1e18


int dp[N][101][2];
vector <int> vec;
int D;
string k;
int n;


//flag 0 means constrained
int solve(int id,int sum,int flag)
{

  //  cout << id << " " << sum << " " << flag << endl;

    if(id==n)
    {
        if(sum%D==0)
            return 1;
        else
            return 0;
    }

    int &ans=dp[id][sum][flag];
    if(ans!=-1)
        return ans;

    int lim;
    if(flag==0)
        lim=vec[id];
    else
        lim=9;
    ans=0;
    for(int dig=0;dig<=lim;dig++)
    {
        int nf=flag;
        if(nf==0 && dig<lim)
            nf=1;
        ans=(ans+solve(id+1,(sum+dig)%D,nf))%mod;
    }
    return ans;
}


int32_t main()  
{
    boost
    // #ifndef ONLINE_JUDGE 
    // NAYAN
    // #endif

        

    cin >> k >> D;
    memset(dp,-1,sizeof dp);

    int l=k.length();
    int i;
    for(i=0;i<l;i++)
    {
        int d=k[i]-'0';
        vec.pb(d);
    }
    n=vec.size();
    int ans=solve(0,0,0);

    cout << (ans-1+mod)%mod;




}