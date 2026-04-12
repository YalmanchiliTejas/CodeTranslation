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
const int INF = 1e8;

//マクロ定義
#define vvint(vec,n,m,l) vector<vector<int>> vec(n, vector<int>(m,l));	// lで初期化
#define vvll(vec,n,m,l) vector<vector<ll>> vec(n,vector<ll>(m,l));
#define vint vector<int>
#define pint pair<int,int>
#define rep(i,a) for(int i=0;i<(a);i++)
#define all(x) (x).begin(),(x).end()
#define debug system("pause")				//デバッグ用

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	vector<bool> gyo(h,false),ret(w,false);
	rep(i, h)
	{
		cin >> a[i];
        rep(j,w)
        {
            if(a[i][j]=='#')
            {
                gyo[i]=true;
                ret[j]=true;
            }
        }
    }
    
    rep(i,h)
    {
        rep(j,w)
        {
            if(gyo[i] && ret[j])
                cout<<a[i][j];
        }
        if(gyo[i])
        cout<<endl;
    }

	return 0;
}