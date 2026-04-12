#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

char a[15][15];

int main() {
	int H, W;
	cin >> H >> W;
	for(int i=1;i<=H;i++)
		scanf("%s", a[i]+1);
	bool yes=1;
	for(int i=1;i<=H;i++)
		for(int j=1;j<=W;j++) {
			if(i==1 && j==1) {
				if( (a[i+1][j]=='#') + (a[i][j+1]=='#') != 1) yes=0;
				continue;
			}
			if(i==H && j==W) {
				if( (a[i-1][j]=='#') + (a[i][j-1]=='#') != 1) yes=0;
				continue;
			}
			if(a[i][j]!='#') continue;
			if( (a[i-1][j]=='#') + (a[i][j-1]=='#') != 1) yes=0;
			if( (a[i+1][j]=='#') + (a[i][j+1]=='#') != 1) yes=0;
			debug("yes %d\n", yes);
		}
	puts(yes?"Possible":"Impossible");
	return 0;
}
