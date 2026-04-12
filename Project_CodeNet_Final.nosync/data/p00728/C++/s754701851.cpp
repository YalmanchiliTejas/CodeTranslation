#include <stdio.h>
#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <sstream>

using namespace std;

#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()))

//typedef complex<double> P;
typedef long long ll;

const int MAX_SIZE = 10000;
const int INF = 1000000000;

int main(){

	int n,s;
	while(cin >> n && !(n == 0)){
		int maxNum = 0;
		vector<int> nums;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			nums.push_back(x);
		}
		sort(nums.begin(),nums.end());
		int sum = 0;
		for(int i = 1; i < nums.size() - 1; i++){
			sum += nums[i];
		}
		cout << (int)((double)sum/(nums.size()-2)) << endl;
	}

	return 0;
}