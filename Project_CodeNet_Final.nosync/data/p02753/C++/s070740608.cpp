// cities to vapori-
// corner cases // int vs ll // cin vs scanf // clear structures // statement // doublesz // math is your friend
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int main(){
	
	fastio;
	string cad;
	cin >> cad;
	set<char> s;
	for(char ch : cad) s.insert(ch);
	cout << (sz(s) > 1 ? "Yes" : "No") << endl;

	return 0;
}
