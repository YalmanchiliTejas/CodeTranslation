#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;

#define YES(n) cout << ((n) ? "YES" : "NO"  ) << endl
#define Yes(n) cout << ((n) ? "Yes" : "No"  ) << endl
#define ANS(n) cout << (n) << endl

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>=(b);i--)

#define ALL(obj) (obj).begin(),(obj).end()

#define pii pair<int,int>

#define pb(a) push_back(a)
#define mp make_pair

int main()
{
	int n;
	cin >> n;
	int alphabetCountMin[26];
	FOR(i,0,26)alphabetCountMin[i] = INF;
	FOR(i,0,n){
		string s;
		cin >> s;
		int alphabetCount[26];
		FOR(j,0,26)alphabetCount[j] = 0;
		FOR(j,0,(int)s.size()){
			alphabetCount[s[j] - 'a']++;
		}
		FOR(j,0,26)alphabetCountMin[j] = min(alphabetCountMin[j], alphabetCount[j]);
	}
	FOR(i,0,26){
		FOR(j,0,alphabetCountMin[i])
			printf("%c", 'a'+i);
	}
	printf("\n");
	return 0;
}
