#include <iostream>
#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <string>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;

typedef long long int ll;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ost;

const ll maxN = 1e7;
const ll INF = 1e17;

ll xs[] = {-1, 1, 0, 0};
ll ys[] = {0, 0, -1, 1};

int main(){
	cin.sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	if(t == 5 or t == 3 or t == 7)
		puts("YES");
	else
		puts("NO");
	return 0;
}