#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<stack>
#include<list>
#include<unordered_map>
#include<unordered_set>

using namespace std;
typedef long long int ll;typedef pair<int, int> P;
const long long mod = 1e9 + 7;
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define ALL(a) (a).begin(),(a).end()



int main(void) {
	int h, w; cin >> h >> w;
	char arr[100][100];
	bool x = 0;
	set<int> hh;
	set<int> ww;
	rep(hi, h)rep(wi, w)cin >> arr[hi][wi];
	rep(hi, h) {
		rep(wi, w) {
			if (arr[hi][wi] == '#')x = 1;
		}
		if (x)ww.insert(hi);//show
		x = 0;
	}
	rep(wi, w) {
		rep(hi, h) {
			if (arr[hi][wi]=='#')x = 1;
		}
		if (x)hh.insert(wi);
		x = 0;
	}
	rep(hi, h) {
		rep(wi, w)
			if (ww.count(hi) && hh.count(wi))
				cout << arr[hi][wi];
		if(ww.count(hi))cout << endl;
	}
	return 0;
}