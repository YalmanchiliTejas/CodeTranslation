#include "bits/stdc++.h"
using namespace std;
#define repr(i,a,b) for(long long i=(long long)(a);i<(long long)(b);i++)
#define rep(i,n) repr(i,0,n)
#define reprrev(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define reprev(i,n) reprrev(i,0,n)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define mp make_pair
#define mt make_tuple
#define MOD 998244353
#define PI 3.1415926535
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<Pi> vPi;
typedef vector<Pll> vPll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;
typedef vector<vector<ll>> vvll;
typedef vector<vector<char>> vvc;
typedef vector<vector<string>> vvs;
typedef vector<vector<double>> vvd;
typedef vector<vector<Pi>> vvPi;
typedef priority_queue<int, vector<int>, greater<int>> pqli;
typedef priority_queue<ll, vector<ll>, greater<ll>> pqlll;
typedef priority_queue<Pi, vector<Pi>, greater<Pi>> pqlP;
string YN(bool y) { return (y?"YES":"NO"); }
string yn(bool y) { return (y?"Yes":"No"); }
string ON(bool y) { return (y?"OK":"NG"); }
int main(void)
{
	int n, m;

	ll ans=0;

	cin>>n>>m;

	vvb a(n, vb(n, false));
	vb visited(n, false);

	vi v(n-1);

	rep(i, m){
		int from, to;
		cin>>from>>to;
		a[from-1][to-1]=true;
		a[to-1][from-1]=true;
	}

	iota(v.begin(), v.end(), 1);
	do{
		repr(i, 1, n) visited[i]=false;

		int node=0;
		rep(i, n-1){
			if(a[node][v[i]]){
				node=v[i]; visited[v[i]]=true;
			}
		}
		bool flag=true;
		repr(i, 1, n){
			if(!visited[i]) flag=false;
		}
		if(flag) ans++;
	}while(next_permutation(v.begin(), v.end()));     // 次の順列を生成
	
	cout<<ans<<endl;
}
