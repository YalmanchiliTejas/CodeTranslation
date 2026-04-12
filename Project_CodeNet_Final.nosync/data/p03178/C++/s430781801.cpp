#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<ll,ll,ll> T;
const long long INF = 1LL<<60;
const int MOD = 1000000000+7;
#define rev(s) (string((s).rbegin(), (s).rend()))
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
// cout << fixed << setprecision(10) << ans << endl; 有効桁数指定
// *min_element(c + l, c + r) *max_element(c + l, c + r) 配列の中のmin-max
// int dx[8]={1,1,0,-1,-1,-1,0,1};
// int dy[8]={0,1,1,1,0,-1,-1,-1};
// int dx[4]={1,0,-1,0};
// int dy[4]={0,1,0,-1};
// ~ は、-1の時だけfalse
// struct Edge {
//   int to, id;
//   Edge(int a, int b): to(a), id(b) {}
// };

ll dp[10010][2][110];


int main(int argc, char const *argv[])
{
	string s;int d;cin>>s>>d;

	int n = (int)s.size();


	dp[0][0][0]=1;


	rep(i,n) {
		rep(j,2) {
			rep(k,d) {
				int e = s[i]-'0';
				if (j==0) {
					dp[i+1][0][(k+e)%d]+=dp[i][j][k];
					dp[i+1][0][(k+e)%d]%=MOD;
					if (e>=1) {
						rep(l,e) {
							dp[i+1][1][(k+l)%d]+=dp[i][j][k];
							dp[i+1][1][(k+l)%d]%=MOD;
						}
					}
				} else {
					rep(l,10) {
						dp[i+1][1][(k+l)%d]+=dp[i][j][k];
						dp[i+1][1][(k+l)%d]%=MOD;
					}
				}
			}
		}
	}

	cout<<(dp[n][0][0]+dp[n][1][0]-1+MOD)%MOD<<endl;


	return 0;
}