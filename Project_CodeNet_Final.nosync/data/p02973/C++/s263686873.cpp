
#include <bits/stdc++.h>
using namespace std;
long long arr[200005];
int MinimumNumIncreasingSubsequences( int n)
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>arr[i];
	cout << MinimumNumIncreasingSubsequences(n)<<endl;
	return 0;
}
