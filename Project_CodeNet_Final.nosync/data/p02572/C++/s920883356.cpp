#include<iostream>
#include<cstdlib>
#include<vector>
#include<unordered_map>
#include<climits>
#include<string>
#include<algorithm>
#include<unordered_set>
//#include<>

using namespace std;

long long unsigned int sum(vector<long long unsigned int>vec, int n)
{
	const unsigned int M = 1000000007;
	vector<long long unsigned int>vecsum(n);
	long long unsigned int ans=0;
	for (int i = n-1; i >-1; i--) {
		ans = ( ans + ( vec[i] % M) ) % M;
		vecsum[i] = ans;
	}
	ans = 0;
	for (int i = 0; i < n-1; i++) {
		vecsum[i] = ((vec[i] % M) * (vecsum[i + 1])) % M ;
		ans = (ans + (vecsum[i] % M)) % M;
	}
	return ans;
}

		

// Driver code 
int main()
{
	int n;
	cin >> n;
	vector<long long unsigned int>vec(n);

	for (int i = 0; i < n; i++)
		cin >> vec[i];

	cout << sum(vec, n);
	return 0;
}

