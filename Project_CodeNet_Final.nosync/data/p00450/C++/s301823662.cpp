#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <iterator>
#include <queue>
#include <stack>
#include <deque>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <string>
#include <cmath>
#include <complex>
#include <functional>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <cstdlib>
#include <cctype>

#define REP(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define rp(i,c) rep(i,(int)c.size())
#define fr(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define mp make_pair
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(u) (u).rbegin(),(u).rend()
#define dbg(x) cerr<<#x<<" = "<<(x)<<endl
#define v_delete(a,b) (a).erase(remove((a).begin(), (a).end(), b), (a).end())
#define v_unique(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define VV(T) vector<vector< T > >
#define init(a,b) memset((a), (b), sizeof((a)))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf=1<<28;
const double EPS=1e-9;
const long long INF = 100001000010000100ll;

template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T StringToInt(string str){T res=0;for(int i=0;i<SIZE(str);i++)res=(res*10+str[i]-'0');return res;}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}

template <class T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
template <class T> void input(T* a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
typedef pair<int,int> pii;


int N;

int d[100000+10];
int dp[100000+10][2];

int main(){

	while(cin >> N, N){
		memset(d, 0 ,sizeof(d));
		memset(dp, 0 ,sizeof(dp));
		rep(i, N){
			int t;
			cin >> t;
			if(i > 0){
				if(i % 2){
					if(dp[i-1][t]==0){
						if(i - dp[i - 1][!t] - 1 >= 0){
							dp[i][t] = dp[i - 1][!t] + dp[i - dp[i - 1][!t] - 1][t] + 1;
							dp[i][!t]=0;
						}else{
							dp[i][t] = dp[i - 1][!t] + 1;
							dp[i][!t]=0;
						}
					}else{
						dp[i][t] = dp[i - 1][t] + 1;
						dp[i][!t] = 0;
					}
				}else{
					dp[i][t] = dp[i - 1][t] + 1;
					dp[i][!t] = 0;
				}
			}else{
				dp[i][t]=1;
			}
			//printf("0:%d 1:%d\n", dp[i][0], dp[i][1]);
		}
		int ans=0;
		int i = N - 1;
		while(i >= 0){
			//cout << i << endl;
			ans+=dp[i][0];
			i -= max(dp[i][0], dp[i][1]);
		}
		cout << ans << endl;
	}

	return 0;

}