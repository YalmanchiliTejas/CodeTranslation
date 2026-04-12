#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
typedef long long int ll;
#define FOR(i,a,n) for(int i=a;i<n;++i)
#define TFOR(i,n)FOR(i,0,n)
#define ALL(x) x.begin(),x.end();
#define pos std::pair<int,int>
const int INF = 1LL << 30;
const int INF_ = 0 - INF;
const ll LLINF = 1LL << 60;
int main() {
	int x, y, z;
	std::cin >> x >> y >> z;
	x -= z;
	std::cout << x / (y+z) << std::endl;
	return 0;

}