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
	int north,south,west,east,up,down;
	up = 1;
	down = 6;
	north = 5;
	south = 2;
	west = 4;
	east = 3;
	int ans,n;
	ans = 1;
	cin >> n;
	if(n==0) break;
	REP(i,n){
	    string s;
	    cin >> s;
	    if(s == "North"){
		int temp = up;
		up = south;
		south = down;
		down = north;
		north = temp;
	    }else if(s=="East"){
		int temp = up;
		up = west;
		west = down;
		down = east;
		east = temp;
	    }else if(s=="West"){
		int temp = up;
		up = east;
		east = down;
		down = west;
		west = temp;
	    }else if(s=="South"){
		int temp = up;
		up = north;
		north = down;
		down = south;
		south = temp;
	    }else if(s=="Right"){
		int temp = north;
		north = west;
		west = south;
		south = east;
		east = temp;
	}else if(s=="Left"){
	    int temp = north;
	    north = east;
	    east = south;
	    south = west;
	    west = temp;
	}
	ans += up;
	}
	cout << ans << endl;
    }
    return 0;
}