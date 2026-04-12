
#include <bits/stdc++.h>
using namespace std;

#define mainspring cout<<"mainspring\n";
#define barrel cout<<"barrel\n";
#define escapement cout<<"escapement\n";

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define INF INT_MAX
#define NINF INT_MIN
#define fs first
#define sd second
#define tik(i,a,b) for(int i = a; i < b; i++)
#define tok(i,a,b) for(int i = a; i >= b; i--)
#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it,args);}

typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << "\n";
    err(++it, args...);
}

const int N = 3e3 + 5;
int n, a[N];
vector< vector< ll > > dp(N, vector<ll>(N,NINF));

ll calc(int i, int j) {

	if(i == j && (i+j+n+1) % 2 == 0)
		return a[i];
	else if(i == j)
		return -a[i];
	else if(dp[i][j] != NINF)
		return dp[i][j];

	if(((i+j+n+1)%2) == 0)
		return dp[i][j] = max(a[i]+calc(i+1,j), calc(i,j-1) + a[j]);
	else
		return dp[i][j] = min(calc(i+1,j)-a[i], calc(i,j-1)-a[j]);	

}

int main() {

	cin >> n;

	tik(i,0,n)
		cin >> a[i];

	cout << calc(0,n-1);
}