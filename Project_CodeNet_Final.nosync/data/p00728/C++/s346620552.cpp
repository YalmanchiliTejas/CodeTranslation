#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define mrep(i,j,n) for(int i = j; i < n; i++)
#define reps(i,n) for(int i = 1; i <= n; i++)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)
#define rreps(i,n) for(int i = n; i >= 1; i--)
#define co(x) cout << x <<endl
#define cs(x) cout << x <<" "
#define cer(x) cerr << x <<endl
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define ERASE(x,val) x.erase(remove(ALL(x), val), x.end())

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll mod = 1e9 + 7;
template<class T>inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T>inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

int main()
{
	vector<int>sums;
	vector<int>mis;
	vector<int>mas;
	vector<int>ns;
	while (true)
	{
		int n; cin >> n;
		if (n == 0)break;
		int tmp;
		int mi = 1000;
		int ma = 0;
		int sum = 0;
		rep(i, n)
		{
			cin >> tmp;
			chmin(mi, tmp);
			chmax(ma, tmp);
			sum += tmp;
		}
		mis.push_back(mi);
		mas.push_back(ma);
		sums.push_back(sum);
		ns.push_back(n);
	}
	rep(i, sz(sums))
	{
		int ans = (sums[i] - mis[i] - mas[i]) / (ns[i] - 2);
		co(ans);
	}
	return 0;
}

