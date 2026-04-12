#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#define lli long long
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define rep0(i,j) for(int i=0;i<j;i++)
#define rep1(i,j) for(int i=1;i<=j;i++)
#define rep0d(i,j) for(int i=j-1;i>=0;i--)
#define MAX 1000000007

using namespace std;

bool cmpf(const pair<lli, lli> left, const pair<lli, lli> right) {
	return left.first < right.first;
}
bool cmps(const pair<lli, lli> left, const pair<lli, lli> right) {
	return left.second < right.second;
}
using namespace std;
lli n, m, p;



int main() {

	cin >> n;
	vector<lli> vec(n);
	vector<lli> ans;

	rep0(i, n) {
		cin >> vec[i];
		auto it = lower_bound(rall(ans),vec[i]);
		if (it == ans.rbegin()) {
			ans.push_back(vec[i]);
		}
		else {
			--it;
			*it = vec[i];
		}
	}
	cout << ans.size();
}
