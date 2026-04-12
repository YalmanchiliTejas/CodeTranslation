#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
#define Nmax 200010
#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for(long long i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define dump(x)  cout << #x << " = " << (x) << endl;
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<P> Graph;
 
int main() {
	int n,mina=MOD;
	cin >> n;
	string s[52];
	REP(i,n) cin >> s[i];
	int cnt[26]={},cnt1=0;
	REP(i,26) cnt[i]=MOD;
	REP(i,26){
		REP(j,n){
			cnt1=0;
			REP(k,s[j].length()){
				if(s[j][k]=='a'+i) cnt1++;
			}
			cnt[i]=min(cnt[i],cnt1);
		}
	}
	REP(i,26){
      	if(cnt[i]!=MOD)
			REP(j,cnt[i]) cout << (char)('a'+i);
	}
	return 0;
}