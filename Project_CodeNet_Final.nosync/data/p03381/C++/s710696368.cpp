#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;

int n;
int x[216000];

vector<int> nums;


int main(){
	cin >> n;
	for(int i = 0; i< n;i++){
		cin >> x[i];
		nums.push_back(x[i]);
	}
	sort(nums.begin(), nums.end());
	int l = nums[n/2 - 1];
	int r = nums[n/2];
	for(int i = 0;i < n;i++){
		if(x[i] <= l)cout << r << endl;
		else cout << l << endl;
	}
	return 0;
				
}
