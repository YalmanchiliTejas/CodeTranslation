#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int rank(char c){
	if(isdigit(c)) return c - '0';
	if(c == 'T') return 10;
	if(c == 'J') return 11;
	if(c == 'Q') return 12;
	if(c == 'K') return 13;
	return 14;
}
bool win(char t, char st, char *a, char *b){
	if((a[1] == t) != (b[1] == t)) return a[1] == t;
	if((a[1] == st) != (b[1] == st)) return a[1] == st;
	return rank(a[0]) > rank(b[0]);
}

int main(){
	char t;
	while(cin >> t, t != '#'){
		char in[4][13][3];
		rep(i, 4) rep(j, 13) cin >> in[i][j];
		
		int sc[2] = {}, w = 0;
		rep(i, 13){
			char st = in[w][i][1];
			rep(j, 4) if(win(t, st, in[j][i], in[w][i])) w = j;
			sc[w % 2]++;
		}
		if(sc[0] > sc[1]) cout << "NS " << sc[0] - 6 << endl;
		else cout << "EW " << sc[1] - 6 << endl;
	}
	return 0;
}