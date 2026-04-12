#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<math.h>
#include<string>
#include <iomanip>
#include<deque>

typedef long long ll;
typedef unsigned long long ull;
typedef int itn;
const ll LINF = 1e18;
const int INF = 1e8;

using namespace std;


//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")				//デバッグ用


int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	cout << 800 * n - (n / 15) * 200 << endl;

}