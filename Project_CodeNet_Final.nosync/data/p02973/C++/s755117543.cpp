#include<bits/stdc++.h>
using namespace std;
#include<vector>
#include<queue>
#define ll long long
#define inf INT_MAX
int MinimumNumIncreasingSubsequences(ll int arr[],ll int n) 
{ 
    multiset<ll int> last; 
  
    // last element in each  increasing subsequence  
    // found so far 
    for (int i = 0; i < n; i++) { 
  
        // here our current element is arr[i] 
        multiset<ll int>::iterator it = last.lower_bound(arr[i]); 
  
        // iterator to the first element larger  
        // than or equal to arr[i] 
        if (it == last.begin()) 
  
            // if all the elements in last larger 
            // than or to arr[i] then insert it into last 
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
  

main()
{
ll int n;
cin>>n;
ll int a[n];
for(int i=0;i<n;i++)
{
	cin>>a[i];
}
cout<<MinimumNumIncreasingSubsequences(a,n)<<endl;
}
