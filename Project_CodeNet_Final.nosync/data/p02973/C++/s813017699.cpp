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
    return last.size();
} 
  
int main() 
{ 
    int ln;
    cin>>ln;
    int arr[ln];
    for(int i=0;i<ln;i++){
        cin>>arr[i];
    }
    int n = sizeof(arr) / sizeof(int);
    cout << MinimumNumIncreasingSubsequences(arr, n); 
    return 0; 
} 