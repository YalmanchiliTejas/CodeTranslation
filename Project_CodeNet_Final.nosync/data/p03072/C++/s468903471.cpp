#include <bits/stdc++.h>

using namespace std;

#define sz(v)           ((int)((v).size()))
#define clr(v, d)       memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0; i<sz(v); ++i)
#define lp(i, n)        for(int i=0; i<(int)(n); ++i)
#define lpi(i, j, n)    for(int i=(j); i<(int)(n); ++i)
#define lpd(i, j, n)    for(int i=(j); i>=(int)(n); --i)
#define INF             1000000000

//#define DEBUG

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, mmax = 0, res = 0;
	cin >> n;
	lp(i, n){
		int num;
		cin >> num;
		if(num >= mmax){
			++res;
			mmax = num;
		}
	}
	cout << res;
	return 0;
}
