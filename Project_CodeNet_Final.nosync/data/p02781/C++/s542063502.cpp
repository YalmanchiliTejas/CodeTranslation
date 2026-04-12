// CPP Program to find the count of 
// numbers in a range where the number 
// does not contain more than K non 
// zero digits 
  
#include <bits/stdc++.h> 
using namespace std; 
  
const long long M = 105; 
  
// states - position, count, tight 
long long dp[M][M][5]; 
  
// K is the number of non zero digits 
long long K; 
  
// This function returns the count of 
// required numbers from 0 to num 
long long countInRangeUtil(long long pos, long long cnt, long long tight, 
                     vector<long long> num) 
{ 
    // Last position 
    if (pos == num.size()) { 
        // If count of non zero digits 
        // is less than or equal to K 
        if (cnt <= K) 
            return 1; 
        return 0; 
    } 
  
    // If this result is already computed 
    // simply return it 
    if (dp[pos][cnt][tight] != -1) 
        return dp[pos][cnt][tight]; 
  
    long long ans = 0; 
  
    // Maximum limit upto which we can place 
    // digit. If tight is 1, means number has 
    // already become smaller so we can place 
    // any digit, otherwise num[pos] 
    long long limit = (tight ? 9 : num[pos]); 
  
    for (long long dig = 0; dig <= limit; dig++) { 
        long long currCnt = cnt; 
  
        // If the current digit is nonzero 
        // increment currCnt 
        if (dig != 0) 
            currCnt++; 
  
        long long currTight = tight; 
  
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
long long countInRange(string s) 
{ 
    vector<long long> num; 
    while (s.size()) { 
        num.push_back(s.back()-'0'); 
        s.pop_back(); 
    } 
    reverse(num.begin(), num.end()); 
  
    // Initialize dp 
    memset(dp, -1, sizeof(dp)); 
    return countInRangeUtil(0, 0, 0, num); 
} 
  
// Driver Code to test above functions 
int main() 
{ 
    string s;
    cin >> s;
    cin >> K;
    long long x = countInRange(s) - countInRange("0");
    if(K==3){
        K = 2;
        x-=(countInRange(s)-countInRange("0"));
        K = -1;
    }
    else if(K==2){
        K=1;
        x-=(countInRange(s)-countInRange("0"));
    }
    cout << x << endl;
} 