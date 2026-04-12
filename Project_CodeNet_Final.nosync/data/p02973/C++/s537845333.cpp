#include <bits/stdc++.h> 
using namespace std; 

int MinimumNumIncreasingSubsequences(int arr[], int n) 
{ 
	multiset<int> last; 

	for (int i = 0; i < n; i++) { 

		multiset<int>::iterator it = last.lower_bound(arr[i]); 

		if (it == last.begin()) 

			last.insert(arr[i]); 

		else { 
			it--; 

			// the largest element smaller than arr[i] is the number 
			// before *it which is it-- 
			last.erase(it); // erase the largest element smaller than arr[i] 
			last.insert(arr[i]); // and replace it with arr[i] 
		} 
	} 
	return last.size(); // our answer is the size of last 
} 

// Driver program 
int main() 
{  int n;
 cin>>n;
 int arr[n];
 for(int i=0;i<n;i++)
   cin>>arr[i];
 cout<< MinimumNumIncreasingSubsequences(arr, n); 
	return 0; 
} 
