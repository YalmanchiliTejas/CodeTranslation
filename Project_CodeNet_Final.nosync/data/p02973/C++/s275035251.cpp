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
            last.erase(it); 
            last.insert(arr[i]); 
        } 
    } 
    return last.size(); // our answer is the size of last 
} 
  
// Driver program 
int main() 
{ 
int n;
cin>>n;
int arr[n+1];
for(int i=0;i<n;i++)
{
	cin>>arr[i];
}
    cout << MinimumNumIncreasingSubsequences(arr, n); 
    return 0; 
} 