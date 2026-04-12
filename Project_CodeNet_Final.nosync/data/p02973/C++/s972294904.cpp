#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
int main() 
{ 
	SPEED
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
    	cin >> arr[i];
    }
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
    cout << last.size() << '\n';
    return 0;      
} 