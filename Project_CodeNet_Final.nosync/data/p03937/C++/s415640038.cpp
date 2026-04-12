#include"bits/stdc++.h"
using namespace std;

//define
#define ALL(a) a.begin(),a.end()
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)
#define debug(x) if(1)cout<<#x<<":"<<x<<endl;
#define DEBUG(x) if(1)cout<<#x<<":"<<x<<endl;
#define ll long long

//constant
const int MOD = 1000000007;

//typedef
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main() 
{
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	REP(i, h)
		cin >> a[i];
	int cnt = 0;
	for(int i=0;i<h;i++)
		for (int j = 0; j < w; j++) {
			if (a[i][j] == '#')
				cnt++;
		}
	if (cnt == w + h - 1)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}