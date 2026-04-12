#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

ll N,M,H,W,K,Q,A,B;
string S;
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
//const ll INF = 1LL << 60;
//typedef pair<ll,ll> P;
typedef pair<int, int> P;
bool chmx(int &a, int b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

bool chmn(int &a, int b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

int main(){
    string s;
    cin >> s;
    int n=s.size();
    int K;
    cin >> K;
    int dp[105][105][2];//i桁目まで決定,j個の非ゼロを使用,k=0一致するかも、k=1大丈夫
    dp[0][0][0]=1;
    rep(i,n)rep(j,n)rep(k,2){
        int nd=s[i]-'0';//i桁目のnの数
        rep(d,10){
            int ni=i+1,nj=j,nk=k;
            if(d!=0){
                nj++;
            }
            if(nj>K)continue;
            if(k==0){
                if(d>nd)continue;
                if(d<nd)nk=1;
            }
            dp[ni][nj][nk]+=dp[i][j][k];
        }
    }
    int ans=dp[n][K][0]+dp[n][K][1];
    cout<<ans<<endl;
    return 0;
}

