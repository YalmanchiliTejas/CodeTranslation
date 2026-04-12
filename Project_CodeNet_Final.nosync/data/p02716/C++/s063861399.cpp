#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <map>
#include <string.h>
#include <array>
#include <bitset>

using namespace std;

const int maxn=2e5+5;
typedef long long ll;
const ll inf=1e17;

int n;
int a[maxn];
ll dp[maxn][2][3];

ll rek(int x, bool p, int br){
	if(x==n && !br){
		return 0;
	}
	else if(x==n){
		return -inf;
	}
//	cout << x << " " << p << " " << br << '\n';
	if(dp[x][p][br]){
		return dp[x][p][br];
	}
	if(p){
		return dp[x][p][br]=rek(x+1, 0, br)+a[x];
	}
	else{
		if(br){
			return dp[x][p][br]=max(rek(x+1, 1, br), rek(x+1, 0, br-1));
		}
		else{
			return dp[x][p][br]=rek(x+1, 1, br);
		}
	}
}

void solve1(){
	cout << max(rek(0, 1, 2), rek(0, 0, 1)) << '\n';
}

void solve2(){
	cout << max(rek(0, 1, 1), rek(0, 0, 0)) << '\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	if(n%2){
		solve1();
	}
	else{
		solve2();
	}
	return 0;
}