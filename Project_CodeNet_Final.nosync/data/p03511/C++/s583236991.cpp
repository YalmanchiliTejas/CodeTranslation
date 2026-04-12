#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint L;
string s, t;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> L;
	cin >> s >> t;
	if(t+s < s+t) swap(s, t);
	
	llint S = s.size(), T = t.size();
	string x, y;
	for(int i = 0; i <= L/S; i++){
		if((L-i*S)%T == 0){
			for(int j = 0; j < i; j++) x += s;
			for(int j = 0; j < (L-i*S)/T; j++) x += t;
			break;
		}
	}
	for(int i = L/S; i >= 0; i--){
		if((L-i*S)%T == 0){
			for(int j = 0; j < i; j++) y += s;
			for(int j = 0; j < (L-i*S)/T; j++) y += t;
			break;
		}
	}
	cout << min(x, y) << endl;
	
	return 0;
}