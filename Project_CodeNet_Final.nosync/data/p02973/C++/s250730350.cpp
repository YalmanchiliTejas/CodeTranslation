#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
#define pb push_back
const ll mod = 1000000007;

void sayNo() {
	cout << "No" << endl;
}

void sayYes() {
	cout << "Yes" << endl;
}

int main() {
	 int N;
	 cin >> N;
	 vector<int> A;

	 for (int i = 0; i < N; i++) {
		 int a;
		 cin >> a;
		 A.push_back(a);
	 }

	 int count = 1;
	 deque<int> nums(1, A[0]);

	 for (int i = 1; i < N; i++) {
		 if (nums[0] >= A[i]) {
			 nums.push_front(A[i]);
			 count++;
			 continue;
		 }
		 auto itr = lower_bound(nums.begin(), nums.end(), A[i]);
		 int id = distance(nums.begin(), itr);
		 nums[id - 1] = A[i];
	 }
	 cout << count << endl;

	 return 0;
}