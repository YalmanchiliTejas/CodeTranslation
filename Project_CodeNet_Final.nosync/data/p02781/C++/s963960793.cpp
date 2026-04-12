#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pl;
typedef vector<pl> vp;
#define fore(i,a,b) for(ll i=(a);i<=(b);++i)
#define rep(i,n) fore(i,0,(n)-1)
#define rfore(i,a,b) for(ll i=(b);i>=(a);--i)
#define rrep(i,n) rfore(i,0,(n)-1)
#define all(x) (x).begin(),(x).end()
const ll INF=1001001001;
const ll LINF=1001001001001001001;
const ll D4[]={0,1,0,-1,0};
const ll D8[]={0,1,1,0,-1,-1,1,-1,0};
template<class T>
bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>
bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
template<class T>
ll sum(const T& a){return accumulate(all(a),0LL);}

ll dp[101][4][2];
void solve(string n, ll k){
    // 0を引く
    dp[0][0][0]=1;
    int m=n.size();
    fore(i,1,m){
        int d=n[i-1]-'0';
        rep(j,k+1){
            if (d==0) {
                dp[i][j][0]+=dp[i-1][j][0];
            } else {
                if(j>0){
                    dp[i][j][0]+=dp[i-1][j-1][0];
                    dp[i][j][1]+=dp[i-1][j-1][0]*(d-1);
                }
                dp[i][j][1]+=dp[i-1][j][0];
            }
            if(j>0)dp[i][j][1]+=dp[i-1][j-1][1]*9;
            dp[i][j][1]+=dp[i-1][j][1];
        }
    }
    cout<<dp[m][k][0]+dp[m][k][1]<<endl;
}

int main(){
    string n;
    cin >> n;
    ll k;
    scanf("%lld",&k);
    solve(n, k);
}
