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


const int nax = 3001;

int DP[nax][nax];
int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin >> n;
	vector <int> A(n);
	for (int i = 0; i<n;i++) {
		cin >> A[i];
	}




	for (int L = n-1; L>=0;L--) {
		for (int R = L; R <n;R++ ) {
			if(L==R) {
				DP[L][R] = A[L];
			} else {	
				DP[L][R] = max(A[L] - DP[L+1][R] , A[R] - DP[L][R-1]);
			}
		}
 	}
	cout << DP[0][n-1]<<endl;
}