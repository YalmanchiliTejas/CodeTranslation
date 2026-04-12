#include <bits/stdc++.h>
#define inchar			getchar
#define outchar(x)		putchar(x)
#define ll long long 
#define int long long //
#define all(v) v.begin(), v.end()
#define SP outchar(' ')
#define trace(x) cerr<<#x<<": "<<x<<" "<<endl;
#define LN outchar('\n')
#define endl '\n'
using namespace std;

template<typename T> void inpos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=0; if(c=='-')neg=1;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
template<typename T> void outpos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do{snum[i++]=n%10+'0';n/=10;}while(n);i=i-1;while(i>=0)outchar(snum[i--]);}
inline void instr(char *str){register char c=0;register int i=0;while(c<33)c=inchar();while(c!='\n'&&c!=' '&&c!=EOF){str[i]=c;c=inchar();++i;}str[i]='\0';}
template <typename T, typename TT> inline void inpos(T &n, TT &m) { inpos(n); inpos(m);}
template <typename T, typename TT ,typename TTT> inline void inpos(T &n, TT &m, TTT &o) { inpos(n,m); inpos(o);}
template <typename T, typename TT ,typename TTT, typename TTTT> inline void inpos(T &n, TT &m, TTT &o , TTTT &p) { inpos(n,m); inpos(o,p);}


vector <int> number;
string K; int d;
const int mod = 1e9+7;
const int maxu = 10000+5;
int DP [maxu][105][2];

int solve(int pos, int cModd, int f) {
	if (pos == number.size()) {
		if (cModd == 0) {return 1;} return 0;
	}
	if(DP[pos][cModd][f] != -1) {return DP[pos][cModd][f];}
	int LMT = 9;
	if (f == 0) {
		LMT = number[pos];
	}
	int ans = 0;
	for(int i= 0; i<=LMT ; i++) {
		int nf = f;
		if (f ==0 && i<LMT) {nf = 1;}
		ans+= solve(pos+1, (cModd+i)%d, nf); ans %= mod;
	}
	DP[pos][cModd][f] = ans;
	return ans;
}


int solve (string a) {
	memset(DP, -1, sizeof(DP));
	number.clear();
	for_each(all(K),[](char c) {number.push_back(c-'0');});
	int x = solve(0,0,0);
	return x;
}

int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >>  d;
	cout << ((solve(K)-1)+mod)%mod<<endl;
	
}