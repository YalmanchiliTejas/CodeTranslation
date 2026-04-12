#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int64_t,int64_t> pll;
typedef vector<int64_t> vl;
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,1,-1,1,-1,-1,1};
const long double PI = acos(-1);
#define INF (2147483647)
#define mod (1000000007)
#define limit (7368791)
#define rep(i,a,b) for (int64_t i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
#define sz(s) (s).size()
#define ALL(a) begin(a),end(a)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

//string N;ll K,n;
string S;ll N,K;
ll nCr(ll nn,ll r){
    if(r>N)return 0;
    if(r==1)return nn;
    if(r==2)return nn*(nn-1)/2;
    if(r==3)return nn*(nn-1)*(nn-2)/6;
    return 0;
}

long long dp(int i, int k, int smaller) {
    if (i == N) {
        if (k == 0) return 1;
        else return 0;
    }
    if (k == 0) return 1;
    
    if (smaller) return nCr(N-i, k) * pow(9, k);
    else {
        if (S[i] == '0') return dp(i+1, k, false);
        else {
            long long zero = dp(i+1, k, true);
            long long aida = dp(i+1, k-1, true) * (S[i] - '1');
            long long icchi = dp(i+1, k-1, false);
            return zero + aida + icchi;
        }
    }
}


void solve() 
{
    cin>>S>>K;
    N=S.size();
    cout<<dp(0,K,0)<<endl;
}

int main()
{
    cin.tie(0);
	ios::sync_with_stdio(false);
    solve();
    return 0;
}
