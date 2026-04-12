#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include <bits/stdc++.h> 
using namespace std;

  
int MinimumNumIncreasingSubsequences(int arr[], int n) 
{ 
    multiset<int> last; 
  
    // last element in each  increasing subsequence  
    // found so far 
    for (int i = 0; i < n; i++) { 
  
        // here our current element is arr[i] 
        multiset<int>::iterator it = last.lower_bound(arr[i]); 
  
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
  
// Driver program 
int main() 
{ 
    int n,l;
    cin >> n;
    int p = 0;
    int arr[n];
    while(cin>>l){
        arr[p] = l;
        p++;
        if (p >= n) {
            break;
        }
    }

    cout << MinimumNumIncreasingSubsequences(arr, n); 
    return 0; 
} 