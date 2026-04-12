#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 105;


int dp[M][M][2];

int K;


int countInRangeUtil(int pos, int cnt, int tight,
					vector<int> num)
{
	
	if (pos == num.size()) {

		if (cnt <= K)
			return 1;
		return 0;
	}

	
	if (dp[pos][cnt][tight] != -1)
		return dp[pos][cnt][tight];

	int ans = 0;


	int limit = (tight ? 9 : num[pos]);

	for (int dig = 0; dig <= limit; dig++) {
		int currCnt = cnt;

		if (dig != 0)
			currCnt++;

		int currTight = tight;


		if (dig < num[pos])
			currTight = 1;


		ans += countInRangeUtil(pos + 1, currCnt,
								currTight, num);
	}
	return dp[pos][cnt][tight] = ans;
}

int countInRange(string& x)
{
	vector<int> num;
	for(int i=0; i<x.size(); ++i){
		num.push_back(x[i]-'0');
	}
	memset(dp, -1, sizeof(dp));
	return countInRangeUtil(0, 0, 0, num);
}


int main()
{
	string x;
	cin>>x;
	cin>>K;
	if( K == 1 ){
		cout<<countInRange(x)-1<<'\n';
	}else if( K == 2 ){
		int a1 = countInRange(x);
		K = 1;
		cout<<a1 - countInRange(x)<<'\n';
	}else if( K == 3 ){
		int a1 = countInRange(x);
		K = 2;
		int a2 = countInRange(x);
		cout<<a1 - a2 << '\n';
	}
	return 0;
}
