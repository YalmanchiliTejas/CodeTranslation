#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll dp[11111][2][100];
string s;
int d;


ll rec(int idx,int f,int x){
    if(idx == -1)return x == 0;
    if(dp[idx][f][x]!=-1)return dp[idx][f][x];
    ll ret=0;
    if(f){
        rep(i, 10){
            ret+=rec(idx - 1, f, (x - i + d) % d);
        }
    }
    else {
        int m = s[idx] - '0';
        rep(i, m){
            ret += rec(idx - 1, 1, (x - i + d) % d);
        }
        ret += rec(idx - 1, 0, (x - m + d) % d);
    }
    return dp[idx][f][x]=ret % mod;
}

int main(){
    cin >> s;
    cin >> d;
	int n = s.size();
	reverse(s.begin(),s.end());
    memset(dp,-1,sizeof(dp));
    cout << (rec(n - 1, 0, 0) + mod - 1) % mod <<endl;
    return 0;
}
