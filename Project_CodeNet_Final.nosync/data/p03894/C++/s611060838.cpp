#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>

using namespace std;

#define mod 1000000007

int main()
{
	int n, q;
	cin >> n >> q;
	int result[100001][2] = {};
	result[0][0] = 1;
	result[1][1] = 1;
	int nowball = 0;
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		if(result[a][1] != result[b][1]){
			swap(result[a][1], result[b][1]);
		}
		if(nowball == a){
			result[b][0] = 1;
			result[a][0] = 0;
			nowball = b;
			result[min(n - 1, b + 1)][1] = 1;
			result[max(0, b - 1)][1] = 1;
		} else if(nowball == b){
			result[a][0] = 1;
			result[b][0] = 0;
			nowball = a;
			result[min(n - 1, a + 1)][1] = 1;
			result[max(0, a - 1)][1] = 1;
		} else {
			result[min(n - 1, nowball + 1)][1] = 1;
			result[max(0, nowball - 1)][1] = 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += (result[i][0] | result[i][1]);
		// cout << endl;
	}
	cout << ans << endl;
}