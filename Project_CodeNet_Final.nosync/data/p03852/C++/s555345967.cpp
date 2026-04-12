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
	char c;
	cin >> c;
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
	    ANS("vowel");
	}else{
	    ANS("consonant");
	}
	return 0;
}
