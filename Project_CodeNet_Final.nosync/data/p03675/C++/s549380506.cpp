#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    bool flag = true;
    int n;
    cin >> n;
    vector<int> nums(n), res;
    deque<int> que;
    for (int i = 0; i < n; i++) cin >> nums[i];
    for (int i = 0; i < n; i++) {
	if (flag) que.push_back(nums[i]);
	else que.push_front(nums[i]);
	flag = !flag;
    }
    for (int x : que) res.push_back(x);
    if (n % 2 == 1) reverse(res.begin(), res.end());
    for (int x : res) cout << x << " ";
    cout << endl;
}
