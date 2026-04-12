#include <bits/stdc++.h> 
#define int long long
using namespace std; 
  
const int M = 500; 
  
// states - position, count, tight 
int dp[M][M][2]; 
  
// K is the number of non zero digits 
int K; 
  
// This function returns the count of 
// required numbers from 0 to num 
int countInRangeUtil(int pos, int cnt, int tight, 
                     vector<int> num) 
{ 
    // Last position 
    if (pos == num.size()) { 
        // If count of non zero digits 
        // is less than or equal to K 
        if (cnt == K) 
            return 1; 
        return 0; 
    } 
  
    // If this result is already computed 
    // simply return it 
    if (dp[pos][cnt][tight] != -1) 
        return dp[pos][cnt][tight]; 
  
    int ans = 0; 
  
    // Maximum limit upto which we can place 
    // digit. If tight is 1, means number has 
    // already become smaller so we can place 
    // any digit, otherwise num[pos] 
    int limit = (tight ? 9 : num[pos]); 
  
    for (int dig = 0; dig <= limit; dig++) { 
        int currCnt = cnt; 
  
        // If the current digit is nonzero 
        // increment currCnt 
        if (dig != 0) 
            currCnt++; 
  
        int currTight = tight; 
  
        // At this position, number becomes 
        // smaller 
        if (dig < num[pos]) 
            currTight = 1; 
  
        // Next recursive call 
        ans += countInRangeUtil(pos + 1, currCnt, 
                                currTight, num); 
    } 
    return dp[pos][cnt][tight] = ans; 
} 
  
// This function converts a number into its 
// digit vector and uses above function to compute 
// the answer 
int countInRange(string x) 
{ 
    vector<int> num; 
    for(int i = 0;i<x.size();i++) { 
        num.push_back(x[i]-'0'); 
      
    } 
    
    // Initialize dp 
    memset(dp, -1, sizeof(dp)); 
    return countInRangeUtil(0, 0, 0, num); 
} 
  
// Driver Code to test above functions 
signed main() 
{ 
   	
   	string s;
   	cin>>s;
   	cin>>K;
   	cout<<countInRange(s)<<endl;

} 