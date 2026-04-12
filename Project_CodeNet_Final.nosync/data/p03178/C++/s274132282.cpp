#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;(i)--)
#define rrep1(i,n) for(int i=((int)(n));i>0;(i)--)
#define sz(c) ((int)(c).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> P;
typedef pair<int, pair<int, int> > PP;
const int MAX=1e4+10;
const ll MOD=1e9+7;

int D;
string K;
int N;
int s[MAX];
int sum[MAX];

ll dp[MAX][100];
ll ans;
void solve(){
    cin>>K;
    cin>>D;
    N=sz(K);
    rep(i,N){
      	s[i]=K[i]-'0';
      	sum[i+1]=(sum[i]+s[i])%D;
    }
  	
    rep(d,s[0]+1)dp[0][d%D]++;
    rep(i,N-1)rep(r,D){
        rep(d,10){
            if(d>s[i+1] && r==sum[i+1]) dp[i+1][(r+d)%D]=(dp[i+1][(r+d)%D]+dp[i][r]-1+MOD)%MOD;
            else dp[i+1][(r+d)%D]=(dp[i+1][(r+d)%D]+dp[i][r])%MOD;
        }
    }
    ans=(dp[N-1][0]-1+MOD)%MOD;
    cout<<ans<<endl;
}

int main(){
    solve();
}