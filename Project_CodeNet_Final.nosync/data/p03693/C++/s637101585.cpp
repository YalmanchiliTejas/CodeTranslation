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
#define vsort(v) sort(v.begin(), v.end());
#define vunique(v) unique(v.begin(), v.end());
#define mp make_pair
typedef long long ll;
typedef pair<int, int> P;
const ll INF = 1e18;


int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int r, g, b;
	cin >> r >> g >> b;
	int tmp = r * 100 + g * 10 + b;
	if(tmp % 4 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;

}
