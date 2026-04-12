#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;


int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	deque<int> que;

	for (int i = 0; i < n; i++){
		int index = lower_bound(que.begin(), que.end(), a[i]) - que.begin();
		if (index) que[index-1] = a[i];
		else que.push_front(a[i]);
	}

	cout << que.size() << endl;
	return 0;
}