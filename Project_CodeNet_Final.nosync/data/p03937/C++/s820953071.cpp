#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define rep(i,n) FOR(i,0,n-1)
#define int long long
#define MOD 998244353
#define MAXN  100005
#define P pair<int,int>

char f[10][10];
int dh[2] = {0,-1},dw[2] = {-1,0};
signed main(){
	
	int h,w;cin>>h>>w;
	int cnt = 0;
	rep(i,h)rep(j,w)
	{
		char s;cin>>s;
		if(s == '#') cnt++;
	}
	
	if(cnt == h+w-1)	cout << "Possible" << endl;
	else cout <<"Impossible" << endl;
	return 0;
	
	
}

//cout << ans << endl;