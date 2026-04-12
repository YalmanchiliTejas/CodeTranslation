#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cstring>

using namespace std;
// ascending order
#define vsort(v) sort(v.begin(), v.end())
// descending order
#define vsort_r(v) sort(v.begin(), v.end(), greater<int>())
#define vunique(v) unique(v.begin(), v.end())
#define mp make_pair
#define ts(x) to_string(x)
#define rep(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define repm(i, a, b) for(int i = (int)a; i > (int)b; i--)
#define bit(a) bitset<8>(a)
#define des_priority_queue priority_queue<int, vector<int>, greater<int> >
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;

#define MAX_V 1000000

#define MAX_H 100
#define MAX_W 100

int H, W;
string a[MAX_H];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);


	cin >> H >> W;
	rep(i, 0, H) cin >> a[i];

	vector<int> del_col, del_row;
	rep(i, 0, H) {
		bool flag = true;
		rep(j, 0, W) {
			if(a[i][j] == '#') {
				flag = false;
				break;
			}
		}
		if(flag) del_row.push_back(i);
	}

	rep(i, 0, W) {
		bool flag = true;
		rep(j, 0, H) {
			if(a[j][i] == '#') {
				flag = false;
				break;
			}
		}
		if(flag) del_col.push_back(i);
	}

	vsort(del_col);
	vsort(del_row);

	rep(i, 0, H) {
		if(binary_search(del_row.begin(), del_row.end(), i)) continue;
		rep(j, 0, W) {
			if(binary_search(del_col.begin(), del_col.end(), j)) continue;
			cout << a[i][j];
		}
		cout << endl;
	}
					
	

}
