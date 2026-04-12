#include <bits/stdc++.h>

using namespace std;

#define sz(v)           ((int)((v).size()))
#define clr(v, d)       memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0; i<sz(v); ++i)
#define lp(i, n)        for(int i=0; i<(int)(n); ++i)
#define lpi(i, j, n)    for(int i=(j); i<(int)(n); ++i)
#define lpd(i, j, n)    for(int i=(j); i>=(int)(n); --i)
//#define INF             1000000000
//#define INF             100000000000000

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void init(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

const int N = 1000;

char arr[N][N];

int mr[N], mc[N];

int main()
{
	int h, w;
	cin >> h >> w;
	lp(i, h)
		lp(j, w){
			cin >> arr[i][j];
			if(arr[i][j] == '.'){
				++mr[i];
				++mc[j];
			}
		}
	lp(i, h){
		lp(j, w)
			if(mr[i] < w && mc[j] < h)
				cout << arr[i][j];
		if(mr[i] < w)
			cout << "\n";
	}
	return 0;
}
