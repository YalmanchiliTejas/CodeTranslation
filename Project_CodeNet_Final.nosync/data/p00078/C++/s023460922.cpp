#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i=(b) - 1;i>=(a);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n-1;i>=0;i--)

#define PB push_back
#define INF (1<<29)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CLR(a) memset(a,0,sizeof(a))
const int dx[] = {-1,0,0,1},dy[] = {0,1,-1,0};

typedef long long int ll;

using namespace std;

int main(){
    while(true){
	int n;
	cin >> n;
	if(n == 0) break;
	vector< vector<int> > m(n,vector<int>(n,-1));
	int x,y,c;
	x = n/2;
	y = n/2;
	c = 1;
	y += 1;
	m[y][x] = c;

	while(c < n*n){
	    c++;
	    if(m[y][x] > 0){
		x = (x+1)%n;
		y = (y+1)%n;
		if(m[y][x] > 0){
		    x = (x-1+n)%n;
		    y = (y+1)%n;
		}
	    }
	    m[y][x] = c;
	}
	REP(i,n){
	    REP(j,n-1){
		printf("%4d",m[i][j]);
	    }
	    printf("%4d\n",m[i][n-1]);
	}
    }
    return 0;
}