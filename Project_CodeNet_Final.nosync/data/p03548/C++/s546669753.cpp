#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<utility>

#define REP(i,x) for(int i=0; i<(int)(x); i++)       // 0 <= i < x
#define REPS(i,x) for(int i=1; i<=(int)(x); i++)     // 0 < i <= x
#define RREP(i,x) for(int i=((int)(x)-1); i>=0; i--) // x > i >= 0
#define RREPS(i,x) for(int i=((int)(x)); i>0; i--)   // x >= i > 0
#define INF 999999999
typedef long long ll;

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main(void){
	int x, y, z;
	cin >> x >> y >> z;
	cout << (x - z) / (y + z) << endl;

	return 0;
}
