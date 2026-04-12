#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll findMaxPoints(vector < int > &nums, int i, int j, vector < vector < ll > > &dp) {
  if (i > j) {
    return 0;
  }
  if (dp[i][j] != -1) {
    return dp[i][j];
  }

  dp[i][j] = max(nums[i] + min(findMaxPoints(nums,i + 2, j, dp), findMaxPoints(nums, i + 1, j - 1, dp)), nums[j] + min(findMaxPoints(nums, i, j - 2, dp), findMaxPoints(nums, i + 1, j - 1, dp)));
  return dp[i][j];
}

ll findTarosPoint(vector < int > &nums) {
  int n = nums.size();
  vector < vector < ll > >dp(n, vector < ll >(n, -1));
  return findMaxPoints(nums, 0, nums.size() - 1, dp);
}

int main() {
  int n;
  cin>>n;
  vector < int > nums(n, 0);
  ll totalPoints = 0;
  for (int i = 0; i < n; i++) {
    cin>>nums[i];
    totalPoints += nums[i];
  }

  ll tarosPoints = 0;
  tarosPoints = findTarosPoint(nums);
  // cout<<"taros points = "<<tarosPoints<<endl;
  ll jirosPoints = totalPoints - tarosPoints;
  cout<<tarosPoints - jirosPoints<<endl;

  return 0;
}
