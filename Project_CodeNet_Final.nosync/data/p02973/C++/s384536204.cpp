// ========================================================================================================
// Library
// ========================================================================================================
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>
using namespace std;

// competitive macro
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b) - 1; i >= (a); i--)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i ,n) for (int i = (n) - 1; i >= 0; i--)
#define LL long long
#define ULL unsigned long long

void fastIOS()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
}
// ========================================================================================================
// ========================================================================================================

//int main()
//{
//	fastIOS();
//
//	int n; cin >> n;
//    vector<int> v;
//    
//    REP(i,n)
//    {
//        int temp;
//        cin >> temp;
//        v.push_back(temp);
//    }
//    
//    int min[n];
//    min[0] = INT_MAX;
//    int cnt = 0;
//    
//    REP(i,n)
//    {
//        if(min[cnt] >= v[i])
//        {
//            cnt++;
//            min[cnt] = v[i];
//        }
//    }
//    
//    cout << cnt << endl;
//    
//    return 0;
//}


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

int main()
{
    fastIOS();
    
    int n; cin >> n;
    int arr[n];
    
    REP(i,n)
    {
        cin>> arr[i];
    }
    
    cout << MinimumNumIncreasingSubsequences(arr,n) << endl;
    
    return 0;
}