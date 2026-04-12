#include <bits/stdc++.h>
#define db(x) cout<<x<<" "
#define db1(x) cout<<x<<'\n'
#define db2(x,y) cout<<x<<" "<<y<<'\n'
#define db3(x,y,z) cout<<x<<" "<<y<<" "<<z<<'\n'
#define rep(i,n) for(int i=0;i<(n);++i)
#define repA(i,a,n) for(int i=a;i<=(n);++i)
#define repD(i,a,n) for(int i=a;i>=(n);--i)
#define pair(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ll  long long int
#define vi vector<ll>
#define pi pair<ll,ll>
#define vpi vector<pair<ll,ll>>
#define ff first
#define ss second
#define all(a) a.begin(),a.end()
#define mod 1000000007
#define MAX_N 10005
using namespace std;
// int dx[4] = {1,-1,0,0};
// int dy[4] = {0,0,1,-1};
ll dp[MAX_N][100][2];

ll getSum(string &num, ll pos, ll sum, bool flag, ll D){
    if(pos==num.length()){
        return sum==0;
    }
    if(dp[pos][sum][flag]!=-1)
        return dp[pos][sum][flag];
    ll limit = 9;
    if(flag)
        limit = num[pos]-'0';
    ll ans = 0;
    repA(i,0,limit){
        ans += getSum(num, pos+1, (sum+i)%D, flag&&i==limit,D);
        ans%=mod;
    }
    return dp[pos][sum][flag] = ans;
}


void solve(){

    memset(dp, -1, sizeof(dp));

    string num;
    cin>>num;

    ll d;
    cin>>d;

    ll ans = (getSum(num, 0, 0, true,d)-1+mod)%mod;

    db1(ans);

}


int main(){ 
int t=1;
//cin>>t;
while(t--){
 solve();
}
  return 0; 
}



