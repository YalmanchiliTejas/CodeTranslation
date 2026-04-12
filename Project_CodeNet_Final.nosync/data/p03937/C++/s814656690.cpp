#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MK make_pair
#define REP(i, a, b) for (int i=a; i < b; i++)


bool sort_by(pi c, pi d){
	return c.S < d.S;
}

int main() {
	int h, w;
	cin >> h >> w;
	char arr[h][w];
	
	int c = 0;
	REP(i, 0, h){
		REP(j, 0, w){
			cin >> arr[i][j];
			if(arr[i][j] == '#') ++c;
		}
	}
	
	int x=0, y=0;
	int ans = 0;
	while(x!= w-1 || y != h-1){
		if(y+1 < h && arr[y+1][x] == '#'){
			++ans;
			++y;
		}
		else if(x+1 < w && arr[y][x+1] == '#'){
			++ans;
			++x;
		}
		else break;
	}
	cout << (ans+1 == c? "Possible":"Impossible");
			

}
