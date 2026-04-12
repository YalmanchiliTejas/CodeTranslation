#include <bits/stdc++.h>

using namespace std;

inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
template<class T> inline T sqr(T x) {return x*x;}

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef long long ll;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair
#define each(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define exist(s,e) ((s).find(e)!=(s).end())
#define range(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  range(i,0,n)
#define clr(a,b) memset((a), (b) ,sizeof(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

const double eps = 1e-10;
const double pi  = acos(-1.0);
const ll INF =1LL << 62;
const int inf =1 << 29;

int table[5][5];
int dp[5][1<<8];
int score[4]={0,60,70,80};

int main(void){
	int T;
	cin >> T;
	rep(loop,T){
		rep(i,5)rep(j,5) cin >> table[i][j];
		rep(i,5)rep(j,1<<8) dp[i][j]=-1;
		dp[0][0]=0;
		rep(i,4)rep(mask,1<<8){
			if(dp[i][mask]==-1) continue;
			rep(mask2,1<<8){
				int sw[4]={0,0,0,0};
				rep(j,4) sw[j]+=(mask>>(2*j))&3;
				rep(j,4) sw[j]+=(mask2>>(2*j))&3;
				rep(j,4) sw[j]%=4;
				int cur=0;
				rep(j,5){
					if(table[i][j]==0)continue;
					int index=table[i][j]-1;
					if(j-1>=0) index=(index+sw[j-1])%4;
					if(j<4) index=(index+sw[j])%4;
					cur+=score[index];
				}
				dp[i+1][mask2]=max(dp[i+1][mask2],dp[i][mask]+cur);
			}
		}
		int ans=0;
		rep(mask,1<<8){
			int sw[4]={0,0,0,0};
			rep(j,4) sw[j]+=(mask>>(2*j))&3;
			rep(j,4) sw[j]%=4;
			int cur=0;
			rep(j,5){
				if(table[4][j]==0)continue;
				int index=table[4][j]-1;
				if(j-1>=0) index=(index+sw[j-1])%4;
				if(j<4) index=(index+sw[j])%4;
				cur+=score[index];
			}
			ans=max(ans,dp[4][mask]+cur);
		}
		cout << ans << endl;
	}
	return 0;
}