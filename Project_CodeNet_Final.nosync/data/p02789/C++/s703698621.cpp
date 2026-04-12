#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<string>
#include <iomanip>
#include<deque>
#include<queue>
#include<stack>
#include<set>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e9;

//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")				//デバッグ用
#define ret return 0

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

#define ketasitei setprecision(15) //15桁表示



int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m;
	cin >> n >> m;

	if (n == m)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
	return 0;
}