#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
bool same(vector<int>v) {
	return all_of(v.begin(), v.end(), [&](const int a) {
		return a == v[0]; });

}
int main() {
	vector<int>as(12);
	for (int i = 0; i < 12; ++i)cin >> as[i];
	sort(as.begin(), as.end());
	if (same(vector<int>(as.begin(),as.begin()+4))&&
		same(vector<int>(as.begin()+4, as.begin() + 8))&&
		same(vector<int>(as.begin()+8, as.begin() + 12))) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
	
	return 0;
}