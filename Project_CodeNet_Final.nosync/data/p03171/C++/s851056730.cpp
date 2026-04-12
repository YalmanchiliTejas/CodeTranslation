#include <bits/stdc++.h>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define eb push_back
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define output(x) cout<<x<<endl;
#define fre(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define frd(i, a, b) for (int i = (int)(a); i >= b; --i)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<pair<int,int> > vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

const int maxn = 3010;

ll a[maxn],dp[maxn][maxn];

ll f(int x,int y){
	if(x==y) return a[x];
	if(dp[x][y]!=-1) return dp[x][y];
	dp[x][y]=max(a[x]-f(x+1,y) , a[y]-f(x,y-1));
	return dp[x][y];
}

int main(){
	cin.tie(0);ios_base::sync_with_stdio(0);	
	int n;
	cin>>n;
	fre(i,1,n) cin>>a[i];
	fre(i,0,maxn-1) fre(j,0,maxn-1) dp[i][j]=-1;
	output(f(1,n));
	return 0;
}