#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <queue>

#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;


int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	rep(i, N) cin >> a[i];

	vector<vector<int>> colors;

	colors.push_back(vector<int>(1, a[0]));

	for(int i=1; i<N; i++) {
		//cout << "a[" << i << "] " << a[i] << ' '; 
		if(a[i]<=colors[colors.size()-1][colors[colors.size()-1].size()-1]) {
			colors.push_back(vector<int>(1, a[i]));
			//cout << "i: " << i << endl;
		} else {	
			//cout << "     i: " << i << ' ';
			int left=-1; 
			int right=colors.size();
			int mid;
			while(left+1<right) {
				mid = (left+right)/2;
				if(a[i]<=colors[mid][colors[mid].size()-1]) {
					left = mid;
				} else {
					right = mid;
				}
			}
			//cout << "mid " << right << endl;
			colors[right].push_back(a[i]);
		}
	}

	cout << colors.size() << endl;
  return 0;
}
