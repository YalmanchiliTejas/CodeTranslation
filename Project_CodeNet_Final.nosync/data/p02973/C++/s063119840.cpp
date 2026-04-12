// C++ program to count the Minimum number of 
// increasing subsequences 
#include <bits/stdc++.h> 
using namespace std; 

int MIS(int arr[], int n) 
{ 
    multiset<int> last; 

    for (int i = 0; i < n; i++) { 

        multiset<int>::iterator it = last.lower_bound(arr[i]); 

        if (it == last.begin()) {

            last.insert(arr[i]); 
        }
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
    int n, i;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<MIS(a, n)<<endl;
    return 0; 
} 
