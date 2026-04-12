#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;



int MinimumNumIncreasingSubsequences(vector <int> &arr, int n)
{
	multiset<int> last;

	
	for (int i = 0; i < n; i++) {

		
		multiset<int>::iterator it = last.lower_bound(arr[i]);

		
		if (it == last.begin())

			
			last.insert(arr[i]);

		else {
			it--;

			
			last.erase(it);
			last.insert(arr[i]); 
		}
	}
	return last.size(); 
}

// Driver program 
int main()
{
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int ans = MinimumNumIncreasingSubsequences(arr, n);
	cout << ans;
}